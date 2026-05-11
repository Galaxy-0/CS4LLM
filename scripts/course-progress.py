#!/usr/bin/env python3
"""Track the CS4LLM course tree and agent handoff state.

The data structure is a tree stored in COURSE_PROGRESS.json.
Most commands traverse every node once, so the complexity is O(n),
where n is the number of course nodes.
"""

from __future__ import annotations

import argparse
import json
from collections import Counter
from datetime import date
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_DATA = ROOT / "COURSE_PROGRESS.json"

STATUS_MARK = {
    "done": "[x]",
    "partial": "[~]",
    "active": "[*]",
    "next": "[>]",
    "planned": "[ ]",
    "paused": "[||]",
    "blocked": "[!]",
    "later": "[-]",
}

SATISFIED = {"done", "partial", "active"}


def load_data(path: Path) -> dict[str, Any]:
    with path.open("r", encoding="utf-8") as f:
        return json.load(f)


def save_data(path: Path, data: dict[str, Any]) -> None:
    data["updated_at"] = date.today().isoformat()
    with path.open("w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)
        f.write("\n")


def walk(nodes: list[dict[str, Any]], depth: int = 0, parent: str | None = None):
    for node in nodes:
        yield node, depth, parent
        yield from walk(node.get("children", []), depth + 1, node["id"])


def build_index(data: dict[str, Any]) -> tuple[dict[str, dict[str, Any]], dict[str, str | None]]:
    index: dict[str, dict[str, Any]] = {}
    parents: dict[str, str | None] = {}
    for node, _depth, parent in walk(data["nodes"]):
        if node["id"] in index:
            raise SystemExit(f"Duplicate node id: {node['id']}")
        index[node["id"]] = node
        parents[node["id"]] = parent
    return index, parents


def title(node: dict[str, Any]) -> str:
    return f"{node['title_en']} / {node['title_zh']}"


def print_tree(data: dict[str, Any], *, status_filter: set[str] | None = None) -> None:
    for node, depth, _parent in walk(data["nodes"]):
        status = node.get("status", "planned")
        if status_filter and status not in status_filter:
            continue
        indent = "  " * depth
        mark = STATUS_MARK.get(status, "[?]")
        pace = node.get("pace", "-")
        print(f"{indent}{mark} {node['id']} :: {title(node)} :: status={status} pace={pace}")


def dependency_state(node: dict[str, Any], index: dict[str, dict[str, Any]]) -> tuple[bool, list[str]]:
    missing: list[str] = []
    for dep in node.get("depends_on", []):
        dep_node = index.get(dep)
        if dep_node is None:
            missing.append(f"{dep}:missing")
        elif dep_node.get("status") not in SATISFIED:
            missing.append(f"{dep}:{dep_node.get('status')}")
    return not missing, missing


def print_next(data: dict[str, Any], *, include_planned: bool = False) -> None:
    index, _parents = build_index(data)
    candidates: list[tuple[str, dict[str, Any], bool, list[str]]] = []
    for node, _depth, _parent in walk(data["nodes"]):
        status = node.get("status", "planned")
        if status not in {"next", "active", "planned"}:
            continue
        ready, missing = dependency_state(node, index)
        if status in {"active", "next"} or (include_planned and ready):
            candidates.append((status, node, ready, missing))

    rank = {"active": 0, "next": 1, "planned": 2}
    candidates.sort(key=lambda item: (rank.get(item[0], 9), item[1].get("pace", "later"), item[1]["id"]))

    for status, node, ready, missing in candidates:
        flag = "ready" if ready else "waiting"
        print(f"{STATUS_MARK.get(status, '[?]')} {node['id']} :: {title(node)} :: {status} :: {flag}")
        if missing:
            print(f"    blocked_by: {', '.join(missing)}")


def print_path(data: dict[str, Any], node_id: str) -> None:
    index, parents = build_index(data)
    if node_id not in index:
        raise SystemExit(f"Unknown node id: {node_id}")

    chain: list[str] = []
    current: str | None = node_id
    while current is not None:
        chain.append(current)
        current = parents[current]
    chain.reverse()

    for depth, item in enumerate(chain):
        node = index[item]
        print(f"{'  ' * depth}{STATUS_MARK.get(node.get('status'), '[?]')} {item} :: {title(node)}")


def set_status(data: dict[str, Any], node_id: str, status: str, note: str | None) -> None:
    if status not in STATUS_MARK:
        allowed = ", ".join(STATUS_MARK)
        raise SystemExit(f"Unknown status: {status}. Allowed: {allowed}")

    index, _parents = build_index(data)
    if node_id not in index:
        raise SystemExit(f"Unknown node id: {node_id}")

    node = index[node_id]
    node["status"] = status
    node["last_touched"] = date.today().isoformat()
    if note:
        node["note"] = note
    data["current_focus"] = node_id if status == "active" else data.get("current_focus", node_id)


def print_handoff(data: dict[str, Any]) -> None:
    index, _parents = build_index(data)
    counts = Counter(node.get("status", "planned") for node, _depth, _parent in walk(data["nodes"]))
    node_count = sum(counts.values())
    focus_id = data.get("current_focus")
    focus = index.get(focus_id, {})

    print("# CS4LLM Course Progress Handoff")
    print()
    print(f"- schema: {data.get('schema')}")
    print(f"- updated_at: {data.get('updated_at')}")
    print(f"- traversal_complexity: O(n), n={node_count} course nodes")
    if focus:
        print(f"- current_focus: {focus_id} :: {title(focus)} :: status={focus.get('status')}")
    else:
        print(f"- current_focus: {focus_id}")
    print(f"- status_counts: {dict(sorted(counts.items()))}")
    print()

    print("## Active")
    for node, _depth, _parent in walk(data["nodes"]):
        if node.get("status") == "active":
            print(f"- {node['id']}: {title(node)}")
    print()

    print("## Next")
    for node, _depth, _parent in walk(data["nodes"]):
        if node.get("status") == "next":
            ready, missing = dependency_state(node, index)
            suffix = "ready" if ready else f"waiting on {', '.join(missing)}"
            print(f"- {node['id']}: {title(node)} ({suffix})")
    print()

    print("## Agent Rules")
    for note in data.get("notes", []):
        print(f"- {note}")
    print("- Do not treat Layer 1/2/3 maps as active work unless COURSE_PROGRESS.json marks them active or next.")
    print("- Prefer tiny runnable exercises when advancing from partial to done.")


def print_stats(data: dict[str, Any]) -> None:
    counts = Counter(node.get("status", "planned") for node, _depth, _parent in walk(data["nodes"]))
    node_count = sum(counts.values())
    print(f"nodes: {node_count}")
    print("traversal: O(n)")
    for status, count in sorted(counts.items()):
        print(f"{status}: {count}")


def main() -> None:
    parser = argparse.ArgumentParser(description="Track CS4LLM course progress tree.")
    parser.add_argument("--file", type=Path, default=DEFAULT_DATA, help="progress JSON file")
    sub = parser.add_subparsers(dest="cmd", required=True)

    show = sub.add_parser("show", help="print the course tree")
    show.add_argument("--status", action="append", help="filter by status; can be repeated")

    next_cmd = sub.add_parser("next", help="print active and next nodes with dependency state")
    next_cmd.add_argument("--include-planned", action="store_true", help="also show planned nodes whose dependencies are ready")
    sub.add_parser("handoff", help="print concise handoff for future agents")
    sub.add_parser("stats", help="print node counts and O(n) traversal note")

    path_cmd = sub.add_parser("path", help="print path from root to a node")
    path_cmd.add_argument("node_id")

    set_cmd = sub.add_parser("set", help="set node status")
    set_cmd.add_argument("node_id")
    set_cmd.add_argument("status")
    set_cmd.add_argument("--note")

    args = parser.parse_args()
    data = load_data(args.file)

    if args.cmd == "show":
        print_tree(data, status_filter=set(args.status) if args.status else None)
    elif args.cmd == "next":
        print_next(data, include_planned=args.include_planned)
    elif args.cmd == "handoff":
        print_handoff(data)
    elif args.cmd == "stats":
        print_stats(data)
    elif args.cmd == "path":
        print_path(data, args.node_id)
    elif args.cmd == "set":
        set_status(data, args.node_id, args.status, args.note)
        save_data(args.file, data)
        print(f"updated {args.node_id} -> {args.status}")


if __name__ == "__main__":
    main()
