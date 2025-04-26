# 🚀 Minishell - Custom Shell Implementation

[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge&logo=bookstack)](LICENSE)
[![Stars](https://img.shields.io/github/stars/ondbeh/minishell?style=for-the-badge&logo=github)](https://github.com/ondbeh/minishell/stargazers)
[![Issues](https://img.shields.io/github/issues/ondbeh/minishell?style=for-the-badge&logo=github)](https://github.com/ondbeh/minishell/issues)
[![42 Project](https://img.shields.io/badge/42_Project-Minishell-darkgreen?style=for-the-badge&logo=42)](https://42.fr/)

> A custom Unix shell implementation with basic functionality inspired by bash

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Contributing](#-contributing)
- [Contacts](#-contacts)
- [License](#-license)

## 📖 Overview

Minishell is a Unix shell implementation that recreates essential functionalities of a command-line interpreter. This project focuses on parsing command syntax, implementing built-in commands, managing processes, and handling signals. It's developed as part of the 42 school curriculum to deepen understanding of process creation and control.

---

## ✨ Features

- ✅ Command line parsing with support for quotes, double quotes, tilde and '\*' wildcard
- ✅ Command execution with PATH variable resolution
- ✅ Built-in commands: echo, cd, pwd, export, unset, env, exit
- ✅ Environment variable expansion
- ✅ Signal handling (Ctrl+C, Ctrl+D, Ctrl+\\)
- ✅ Redirections (input, output, append) and pipes
- ✅ Error handling with appropriate error messages and return values
- ✅ Command history using readline library

---

## 🎮 Demo

![Minishell Demo](screenshots/demo.gif)

---

## 🔧 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ondbeh/minishell.git
   ```
2. Navigate to the project directory:
   ```bash
   cd minishell
   ```
3. Compile the project:
   ```bash
   make
   ```

### Requirements

- GCC compiler
- Make
- Readline library

For Debian/Ubuntu:

```bash
sudo apt-get install libreadline-dev
```

For macOS:

```bash
brew install readline
```

---

## 📚 Usage

Run the shell:

```bash
./minishell
```

### Supported Features

| Feature      | Description|
| ------------ | ----------- | 
| Commands     | Execute commands found in `$PATH`           |
| Quotes       | Handle single `'` and double `"` quotes          |
| Redirections | `<` (input), `>` (output), `>>` (append), `<<`(heredoc)  |
| Pipes        | `\|` to pipe from first command `STD_OUT` to second command `STD_IN`|
| Logical Operators | `&&` (and),  `\|\|` (or) to chain commands|
| Parenthesis  | `(` and `)` to determine command priority |
| Wildcards    | `*` for pattern matching in current working directory |
| Variables    | `$VAR` environment variable expansion    |
| Exit status  | `$?` for last command's exit status      |
| Signals      | Ctrl+C, Ctrl+D, Ctrl+\\ handling         |

---

## 🤝 Contributing

- [Konrad Mühlbauer](https://github.com/Komu211)
- [Ondřej Běhávka](https://github.com/ondbeh)

---

## 📜 License

This project is licensed under the MIT License - see the [license](LICENSE) file for details.
