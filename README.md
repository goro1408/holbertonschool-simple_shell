# C - Simple Shell
This is a simple shell implementation written in C.

## Features

- Interactive command prompt
- Basic command execution
- Built-in 'env' and 'exit' command

## Compilation
To compile the shell, use the following command:
'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh'

## Usage
./hsh

## Commands
The shell displays a prompt (#cisfun$) if attached to a terminal.
Enter any command to execute it. The shell uses execve to run the command.

## Examples
#cisfun$ ls
file1.txt file2.txt
#cisfun$ env
HOME=/home/user
PATH=/usr/local/bin:/usr/bin:/bin
...
#cisfun$ exit
