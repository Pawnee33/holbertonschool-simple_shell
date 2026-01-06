# 🐚 Simple Shell — `hsh`

## 👀 Overview

A shell is a program that:
1. displays a prompt (in interactive mode),
2. reads user input from `stdin`,
3. tokenizes the line into a command + arguments,
4. handles builtins,
5. searches for the command using `PATH` when needed,
6. executes the program in a child process,
7. returns an exit status.

---

## ✅ Features

- Execute commands using absolute/relative paths (e.g. `/bin/ls`)
- Command lookup using the `PATH` environment variable
- Argument parsing/handling
- Error handling (command not found, permission denied, etc.)
- Interactive and non-interactive modes (piping)

---

## 📖 Man Page


## ✍️ Authors

Pawnee  
Anthony D.