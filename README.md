# Simple Shell Project

## Overview

This project is a lightweight Unix shell written in C. The shell operates by taking a user-entered command line, tokenizing it,
and then executing the corresponding command, much like a traditional Unix shell (`sh`).

## Features

- **User Input Parsing:** The shell parses user input to extract commands and arguments.
- **Command Execution:** Executes commands by creating child processes and utilizing system calls.
- **Tokenization:** Implements a tokenizer to break down user input into meaningful components.
- **Error Handling:** Provides basic error handling for invalid commands or execution failures.

## Getting Started

### Installation

1. [Clone the repository]
2. [Compile the code]
3. [Run the executable]

## Usage

1. Open a terminal.
2. Navigate to the project directory.
3. Run the shell executable.
4. Enter commands, and the shell will tokenize and execute them.

## Example

./hsh

$ ls -l

$ echo "Hello, Shell!"

or

echo "ls -l" | ./hsh

echo "echo HI" | ./hsh
