# AI_USAGE.md

This file discloses how AI assistance (Claude, by Anthropic) was used
while building this project, and — just as importantly — what it was
not used for.

## What AI was used for

- **Interpreting errors and stack traces.** When code failed to
  compile or crashed, AI was used to read the compiler error or crash
  output and explain what it meant and where the problem was.
- **Syntax corrections.** Fixing C++ syntax-level mistakes — for
  example, a missing parameter type in a function declaration, or
  printing a string literal instead of a variable's value — once the
  intended behavior was already decided.
- **General syntax questions.** Clarifying how specific C++ language
  features work (e.g. function parameters, `cout` formatting, loop
  syntax) while implementing logic that had already been designed.

## What AI was not used for

- The feature set (add, list, mark complete/reopen, delete), the
  `Task` struct's fields, the choice to track pending and completed
  tasks as two separate vectors, the menu flow, and all other program
  logic were designed and written independently.
- AI was not used to generate the program's control flow or
  algorithmic approach — only to fix syntax-level issues and explain
  errors encountered while implementing logic that was already
  decided.

## Why this disclosure

Documenting AI usage transparently distinguishes which parts of this
project reflect original design work from parts where AI helped with
implementation mechanics (syntax, compiler errors) — in line with
common academic and project-integrity expectations for AI-assisted
coursework or personal projects.
