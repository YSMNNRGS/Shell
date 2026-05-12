# FalconShell

FalconShell is a simple command-line shell written in C for an Operating Systems project.  
It demonstrates basic shell behavior, process creation, command execution, built-in commands, and command history.

## Project Overview

This project implements a mini Linux shell that allows users to enter commands through a custom prompt. The shell reads user input, parses the command, checks whether it is a built-in command, and either executes it internally or runs it as an external Linux command.

The project is designed to demonstrate core Operating System concepts such as process creation, parent-child process handling, system calls, and process synchronization.

## Features

- Custom shell prompt: `FalconShell>`
- Reads user input from the terminal
- Parses commands and arguments
- Executes external Linux commands
- Supports built-in commands
- Handles invalid commands without crashing
- Stores and displays command history
- Uses modular C files for clean project structure

## Supported Commands

### External Linux Commands

FalconShell can run common Linux commands such as:

```bash
pwd
ls
ls -l
date
mkdir foldername
touch filename
cat filename
