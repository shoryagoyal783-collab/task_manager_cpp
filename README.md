# Daily Task Scheduler (console task manager)

A simple command-line task manager written in C++. You can add tasks
with a name, notes, priority, and deadline; list them; mark tasks
complete or reopen them; and delete tasks — all through a numbered
menu, for the current session.

## Build it

Requires a C++17-capable compiler (e.g. g++ or clang++).

```bash
g++ -O2 -std=c++17 -Wall task_manager.cpp -o task_manager
```

## Run it

```bash
./task_manager
```

## Features

- **Add a task** — name, optional notes, priority (High/Medium/Low),
  optional deadline.
- **List tasks** — shows every pending (not yet completed) task with
  its notes, priority, and deadline.
- **Mark complete / reopen** — move a pending task to a completed list,
  or move a completed task back to pending.
- **Delete a task** — remove a pending task by its number.

## How task names and notes are entered

Task names and notes are read with `cin >>`, which stops at the first
space. Because of this, task names should use underscores instead of
spaces (e.g. `Write_report`), as the program's own prompt asks. Enter
`0` for notes or deadline to leave them blank.

## Time and space complexity

Let `N` be the number of pending tasks and `M` be the number of
completed tasks at the time of the operation.

| Operation | Time complexity | Why |
|---|---|---|
| Add a task | O(1) amortized | `vector::push_back` |
| List tasks | O(N) | Iterates every pending task once |
| Mark a task complete | O(N) | Displays the pending list (O(N)), then `vector::erase` at an arbitrary index shifts the remaining elements (O(N)) |
| Reopen a task | O(M) | Displays the completed list (O(M)), then `vector::erase` shifts the remaining elements (O(M)) |
| Delete a task | O(N) | `vector::erase` at an arbitrary index shifts the remaining elements |

**Space complexity:** O(N + M) — one `Task` struct is stored per task
currently tracked (pending plus completed). Deleting a task frees its
slot; completing or reopening a task moves it between the two vectors
rather than duplicating it permanently.

These are fine for a personal task list of any realistic size. The
`vector::erase` cost (shifting elements after the removed one) is the
main cost to be aware of if this were extended to manage a very large
number of tasks at once.

## Known limitations

These reflect the current, verified behavior of the program — useful
to know if you plan to demo it or hand it to someone else to try:

- **No way to quit from the menu.** There is no "exit" option. Closing
  the program requires closing the terminal or pressing Ctrl+C.
  Relatedly, if the input stream runs out (e.g. piping a fixed set of
  commands into the program) or an unreadable value is entered where a
  number is expected, `cin` enters a failed state and the menu will
  loop indefinitely without accepting further input.
- **No persistence between runs.** All tasks exist only in memory for
  as long as the program is running — closing it discards everything.
  The message `Loaded N task(s) from tasks_data.txt.` describes a file
  being loaded, but no file is actually read from or written to in
  this version; `N` is simply a counter of how many tasks have been
  added so far in the current session.
- **The task counter never decreases.** The number shown in
  `Loaded N task(s)...` counts every task ever added during the
  session — it does not go down when a task is deleted, so it can be
  higher than the number of tasks actually listed.
- **"List / search / filter" only lists.** The menu label for option 2
  mentions search and filter, but the current implementation only
  lists all pending tasks in the order they were added, with no search
  or filter step.
- **Delete doesn't show the task list first.** Option 4 asks directly
  for a task number without printing the current list — check the
  numbering with option 2 first, since list order can shift after a
  deletion.
- **Completed tasks can't be listed, edited, or deleted directly** —
  the only way to see a completed task is while choosing one to reopen
  from option 3.
