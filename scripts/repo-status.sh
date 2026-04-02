#!/usr/bin/env bash

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

entries=(
  ".|workspace|top-level workspace manager"
  "00-Archive-Early-Experiments|archive|reference materials and early experiments"
  "06-MIT-6.S081-xv6-labs|repo|active xv6 lab repository"
  "07-Stanford-CS144-Sponge|placeholder|waiting for official CS144 skeleton"
  "08-CMU-15-445-BusTub|repo|active BusTub repository"
  "09-MIT-6.824-Distributed|repo|active 6.824 repository"
  "10-Stanford-CS143-Compiler|placeholder|waiting for official CS143 skeleton"
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

print_git_entry() {
  local dir="$1"
  local kind="$2"
  local note="$3"
  local repo_path="$ROOT/$dir"
  local branch
  local upstream
  local state
  local last_commit

  branch="$(git_branch "$repo_path")"
  upstream="$(git_upstream "$repo_path")"
  state="$(git_state "$repo_path")"
  last_commit="$(git_field "$repo_path" '%h %s')"

  printf '%-32s  %-11s  %-14s  %-18s  %-6s  %s\n' "$dir" "$kind" "$branch" "$upstream" "$state" "$last_commit"
  printf '  note: %s\n' "$note"
}

print_non_git_entry() {
  local dir="$1"
  local kind="$2"
  local note="$3"

  printf '%-32s  %-11s  %-14s  %-18s  %-6s  %s\n' "$dir" "$kind" "-" "-" "-" "-"
  printf '  note: %s\n' "$note"
}

printf 'Workspace: %s\n' "$ROOT"
printf '%-32s  %-11s  %-14s  %-18s  %-6s  %s\n' "path" "kind" "branch" "upstream" "state" "last commit"
printf '%s\n' "----------------------------------------------------------------------------------------------------------------"

for entry in "${entries[@]}"; do
  IFS='|' read -r dir kind note <<<"$entry"
  if [[ -d "$ROOT/$dir/.git" ]]; then
    print_git_entry "$dir" "$kind" "$note"
  else
    print_non_git_entry "$dir" "$kind" "$note"
  fi
done
