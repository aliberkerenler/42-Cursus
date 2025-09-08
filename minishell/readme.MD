# minishell

A small, POSIX-like command-line shell implemented in C as a learning/project exercise.

This repository provides a compact shell with tokenization, parsing, redirections (including heredoc), pipelines, basic builtins, signal handling and environment management. It's implemented with a focus on clarity and following common 42-school/minishell project constraints.

## Highlights
- Tokenizer & parser supporting words, pipes, redirections and heredoc
- Command execution with pipelines and child process management
- Builtin commands: echo, pwd, cd, env, export, unset, exit
- Heredoc support with variable expansion and temporary heredoc files
- Proper signal handling for interactive and child contexts

## Project structure

- `main.c` — program entry, main loop, history handling
- `include/` — public headers and type definitions (`minishell.h`, `structs.h`, `main.h`, ...)
- `src/` — implementation split into modules:
	- `parser/` — tokenization and parsing into command structs
	- `executor/` — executing commands, pipelines and builtins
	- `redirections/` — input/output redirections and heredoc handling
	- `builtins/` — builtin implementations
	- `signals/` — signal handlers and setups
	- `env/` — environment utilities
- `libft/` — small helper library used by the project
- `Makefile` — build targets

## Build

Requirements:
- A POSIX-compatible system (Linux/macOS)
- `cc` (or compatible C compiler)
- `make`
- `readline` development headers (used for input & history)

To build:

```bash
make
```

This will build the `minishell` binary and statically link against the bundled `libft` and the system `readline` library.

Notes on compilation flags
- The Makefile compiles with `-Wall -Wextra -Werror` to keep the code warning-free. If you see a warning promoted to an error during development, prefer fixing the root cause in code rather than removing `-Werror`.

## Run

Start the shell with:

```bash
./minishell
```

It provides a simple prompt (`minishell> `). Type commands, use pipes (`|`), redirections (`<`, `>`, `>>`) and heredoc (`<<`).

Examples:

```bash
minishell> echo hello world
minishell> ls -la | grep src
minishell> cat < input.txt
minishell> cat << EOF
> hello $USER
> EOF
```

Builtin commands
- `echo [args...]` — prints arguments
- `pwd` — prints current working directory
- `cd <dir>` — change directory (updates internal PWD state)
- `env` — prints current environment
- `export KEY=VAL` — set environment variables
- `unset KEY` — remove environment variables
- `exit [n]` — exit shell with code `n` (or last status)

Heredoc behavior
- Heredoc lines are read interactively and stored in temporary files under `/tmp`.
- Variable expansion is performed for unquoted heredocs; quoted heredoc delimiters disable expansion.

Signals
- Interactive prompt: SIGINT (Ctrl-C) is handled to return to prompt without exiting the shell. Child processes reset to child behavior.
- Heredoc reading sets up dedicated signal handling to correctly interrupt heredoc input.

Code style & conventions
- The code follows a modular C style with small functions and header-driven interfaces.
- Types and structures are in `include/structs.h`.

Testing
- The repository doesn't include an automated test harness. Manual testing by exercising builtins, pipelines, redirections and heredoc is recommended.

Contributing
- Fork the repo, create a feature branch, and open a pull request.
- Keep commits small and focused. Run `make` and ensure no warnings appear.

Possible improvements
- Add an automated test suite (shell script harness or unit tests)
- Improve builtin argument parsing and error messages
- Implement more POSIX builtins or job control (background processes)

License
This project is licensed under the MIT License — see the `LICENSE` file for details.

Authors
- Umut Alkan
- Ali Berke Erenler

Credits
- Project scaffold and libft by the repository authors.

