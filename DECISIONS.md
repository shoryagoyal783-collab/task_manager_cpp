# DECISIONS.md

## Design decision: two separate vectors for pending vs. completed tasks

**Decision:** Pending tasks live in `task`, a `vector<Task>`. Completed
tasks live in a second, separate `vector<Task>` called `completedTask`.
Marking a task complete erases it from `task` and pushes it into
`completedTask`; reopening does the reverse.

**Why:** This keeps "pending" and "completed" as two naturally distinct
lists without needing to filter one combined list by a `completed`
flag every time the menu lists tasks. It also makes "mark complete" and
"reopen" read as a straightforward move between two containers, which
matches how the menu phrases the option ("Mark complete/reopen task").

**Trade-offs:** A completed task isn't visible anywhere except while
choosing one to reopen (option 3) — there's no "view completed tasks"
option on its own. The task's data is copied into the new vector and
erased from the old one on every move, rather than just flipping a
flag in place. If dependencies between tasks were added later (one
task requiring another to finish first), two separate containers would
make that harder to track than a single list filtered by status.

## Design decision: `cin >>` for task name and notes, instead of `getline`

**Decision:** Task name and notes are read with `cin >> t.task_name`
and `cin >> t.notes`, which stop at the first whitespace character.

**Why:** `cin >>` is simpler to use consistently throughout the
program than mixing it with `getline`, which requires extra handling
for the leftover newline character left in the input buffer after a
previous `cin >> someInt`. Avoiding that mix keeps every input line in
the program working the same way.

**Trade-offs:** A task name or note can only be a single word — spaces
aren't allowed, so the user is asked to substitute underscores
instead, and the program doesn't convert them back to spaces when
displaying the task later.

## Design decision: priority stored as a plain `int` (1/2/3)

**Decision:** `Task::priority` is an `int`, validated to be 1, 2, or 3
(defaulting to 2/Medium if an out-of-range value is entered), and
translated to "High"/"Medium"/"Low" text only at display time.

**Why:** A plain `int` with a simple range check is less code than
defining and validating against an `enum` or a set of string labels.

**Trade-offs:** The display logic (an `if`/`else if`/`else` chain)
has to be repeated anywhere the priority is shown, instead of being a
single lookup. Reading the stored value on its own (e.g. `priority == 1`)
doesn't self-document what it means without checking how it's
displayed elsewhere.

## Design decision: no file persistence in this version

**Decision:** Tasks are kept only in the `task` and `completedTask`
vectors for the lifetime of the program; nothing is read from or
written to disk.

**Why:** Keeps this version focused on the in-session add/list/
complete/reopen/delete logic without also deciding on a save file
format, escaping rules for special characters, and load/save code
paths.

**Trade-offs:** All tasks are lost when the program exits. The
`Loaded N task(s) from tasks_data.txt.` message describes a load step
that doesn't actually happen — see `README.md`'s Known Limitations for
this specific gap. Adding real persistence later (e.g. a simple
tab-separated text file, one task per line) would be a natural next
step.

## Design decision: single infinite menu loop (`while(1)`), no exit option

**Decision:** The entire program runs inside `while(1)`, with no
branch that breaks out of the loop or returns from `main`.

**Why:** Matches the feel of a menu you keep coming back to, without
yet needing to design a dedicated "0) Exit" branch and decide what, if
anything, should happen on exit (e.g. a save step, once persistence
exists).

**Trade-offs:** There's currently no way to close the program from
within its own menu — the user has to close the terminal or press
Ctrl+C. If the input stream runs out or supplies something unexpected
where a menu number is expected, the loop does not detect this and
will repeat without accepting further input, rather than exiting
gracefully.
