#!/usr/bin/env bash

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

entries=(
  ".|workspace|top-level workspace manager"
  "00-Archive-Early-Experiments|archive|reference materials and early experiments"
  "06-MIT-6.S081-xv6-labs|repo|active xv6 lab repository"
  "07-Stanford-CS144-Sponge|placeholder|waiting for official CS144 skeleton"
  "08-CMU-15-445-BusTub|repo|active BusTub repository"
  "09-MIT-6.5840-Distributed-Systems|repo|active 6.5840 repository"
  "10-Stanford-CS143-Compiler|workspace-code|active compiler practice: clox and nanoc"
)

git_field() {
  local repo_path="$1"
  local format="$2"
  git -C "$repo_path" log -1 --pretty=format:"$format" 2>/dev/null || printf '%s' "-"
}

git_branch() {
  local repo_path="$1"
  git -C "$repo_path" symbolic-ref --quiet --short HEAD 2>/dev/null \
    || git -C "$repo_path" rev-parse --short HEAD 2>/dev/null \
    || printf '%s' "-"
}

git_upstream() {
  local repo_path="$1"
  git -C "$repo_path" rev-parse --abbrev-ref --symbolic-full-name '@{upstream}' 2>/dev/null || printf '%s' "-"
}

git_state() {
  local repo_path="$1"
  if [[ -n "$(git -C "$repo_path" status --porcelain 2>/dev/null)" ]]; then
    printf '%s' "dirty"
  else
    printf '%s' "clean"
  fi
}

git_sync() {
  local repo_path="$1"
  local upstream
  local counts
  local ahead
  local behind

  upstream="$(git_upstream "$repo_path")"
  if [[ "$upstream" == "-" ]]; then
    printf '%s' "-"
    return
  fi

  counts="$(git -C "$repo_path" rev-list --left-right --count HEAD..."$upstream" 2>/dev/null || printf '%s' "- -")"
  read -r ahead behind <<<"$counts"

  if [[ "$ahead" == "0" && "$behind" == "0" ]]; then
    printf '%s' "aligned"
  elif [[ "$ahead" != "0" && "$behind" == "0" ]]; then
    printf 'ahead %s' "$ahead"
  elif [[ "$ahead" == "0" && "$behind" != "0" ]]; then
    printf 'behind %s' "$behind"
  else
    printf 'ahead %s, behind %s' "$ahead" "$behind"
  fi
}

workspace_path_state() {
  local path="$1"
  if [[ -n "$(git -C "$ROOT" status --porcelain -- "$path" 2>/dev/null)" ]]; then
    printf '%s' "dirty"
  else
    printf '%s' "clean"
  fi
}

workspace_path_last_commit() {
  local path="$1"
  git -C "$ROOT" log -1 --pretty=format:'%h %s' -- "$path" 2>/dev/null || printf '%s' "-"
}

print_git_entry() {
  local dir="$1"
  local kind="$2"
  local note="$3"
  local repo_path="$ROOT/$dir"
  local branch
  local upstream
  local state
  local sync
  local last_commit

  branch="$(git_branch "$repo_path")"
  upstream="$(git_upstream "$repo_path")"
  state="$(git_state "$repo_path")"
  sync="$(git_sync "$repo_path")"
  last_commit="$(git_field "$repo_path" '%h %s')"

  printf '%-32s  %-14s  %-14s  %-18s  %-6s  %-17s  %s\n' "$dir" "$kind" "$branch" "$upstream" "$state" "$sync" "$last_commit"
  printf '  note: %s\n' "$note"
}

print_non_git_entry() {
  local dir="$1"
  local kind="$2"
  local note="$3"
  local state
  local last_commit

  state="$(workspace_path_state "$dir")"
  last_commit="$(workspace_path_last_commit "$dir")"

  printf '%-32s  %-14s  %-14s  %-18s  %-6s  %-17s  %s\n' "$dir" "$kind" "-" "-" "$state" "-" "$last_commit"
  printf '  note: %s\n' "$note"
}

print_missing_entry() {
  local dir="$1"
  local kind="$2"
  local note="$3"

  printf '%-32s  %-14s  %-14s  %-18s  %-6s  %-17s  %s\n' "$dir" "$kind" "-" "-" "missing" "-" "-"
  printf '  note: %s\n' "$note"
}

printf 'Workspace: %s\n' "$ROOT"
printf '%-32s  %-14s  %-14s  %-18s  %-6s  %-17s  %s\n' "path" "kind" "branch" "upstream" "state" "sync" "last commit"
printf '%s\n' "--------------------------------------------------------------------------------------------------------------------------------"

for entry in "${entries[@]}"; do
  IFS='|' read -r dir kind note <<<"$entry"
  if [[ ! -e "$ROOT/$dir" ]]; then
    print_missing_entry "$dir" "$kind" "$note"
  elif [[ -d "$ROOT/$dir/.git" ]]; then
    print_git_entry "$dir" "$kind" "$note"
  else
    print_non_git_entry "$dir" "$kind" "$note"
  fi
done
