
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
=======

# C - Simple Shell


# Description
simple UNIX command interpreter.

Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0].


# How it Works
- Get the code and compile it 
- Run the hsh this command ./hsh
- Put the correct commands and press ENTER
- and to exit the program write exit or press ctl+d.
 
## Installation
Download the repo

```bash
https://github.com/Gabyriv/holbertonschool-simple_shell.git
```
## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Example
Your shell should work like this in interactive mode:

```bash
./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
```
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$ cat test_ls_2
/bin/ls
/bin/ls
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Authors

- [@Sigidibau](https://www.github.com/sigidibau)
- [@Gabyriv](https://github.com/Gabyriv)
>>>>>>> e455a38 (complete readme)
