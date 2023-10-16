#SIMPLE SHELL
We created a basic version of the Unix shell from scratch. A program that takes commands from the keyboard and gives them to the operating system to perform. The shell can perform commands such as listing files in current working directory by typing ls, exit, among others. It works in both interactive and non-interactive mode.

#The following are the allowed functions and system calls;

access, chdir, close, closedir, execve, exit, _exit, fflush, fork,free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write.

#This simple shell is a Shell interface written in C programming language that gives to the user a prompt #cisfun$, after it accepts,it executes a user inputted commandin a separate process called child process.

#File Descriptions
AUTHORS: Has the names of this project's contributors.
executor.c: Contains the function that executes shell commands.
str_hundler1.c, str_hundler.c: Contains functions that are used to manipultate and get data about strings like finding string length and splitting a string.
built_in.c: Includes functions to perform built-in shell command operations like exit.
main.h: Holds all function prototypes and headers.
main.c: The shell's entry point i.e contains the main method.
man_1_simple_shell: A manual for the shell.
readline.c: Responsible for picking commands typed into the shell.
handle_path.c: Contains function get_path to get the path for command. For example when a user types ls instead of \bin\ls.
getoken.c: contain function to tokenize the line entred.
errors.c: contain function that print errors.

#Builtin functions

env: Print current environment variables
setenv: Set new environment variable setenv var_name va_value
unsetenv: Remove environment variable unsetenv var_name va_value

#How to use the shell:
#Install;
(your_terminal)$ git clone <this repository>
(your_terminal)$ cd simple_shell
#Compile:
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
Usage: non-interactive mode
echo "/bin/ls" | ./hsh
Usage: interactive mode
(your_terminal)$ ./hsh
#Example

/bin/ls -l
total 80
-rw-r--r-- 1 root root   138 Oct 12 08:40 AUTHORS
-rw-r--r-- 1 root root  1705 Oct 13 09:41 built_in.c
-rw-r--r-- 1 root root   912 Oct 13 08:38 environ.c
-rw-r--r-- 1 root root   574 Oct 13 09:43 errors.c
-rw-r--r-- 1 root root   740 Oct 13 08:43 executor.c
-rw-r--r-- 1 root root   850 Oct 13 09:53 getoken.c
-rw-r--r-- 1 root root   825 Oct 13 08:51 handle_path.c
-rwxr-xr-x 1 root root 22568 Oct 13 10:09 hsh
-rw-r--r-- 1 root root   637 Oct 13 09:02 main.c
-rw-r--r-- 1 root root   282 Oct 13 09:32 memory.c
-rw-r--r-- 1 root root   363 Oct 13 09:05 readline.c
-rw-r--r-- 1 root root    29 Oct 11 19:05 README.md
-rw-r--r-- 1 root root  1114 Oct 13 10:09 shell.h
-rw-r--r-- 1 root root  1339 Oct 13 09:29 str_hundler1.c
-rw-r--r-- 1 root root  1957 Oct 13 09:22 str_hundler.c

#Bugs
At this time, there are no known bugs.

#Authors:

Ismail-Taha <https://github.com/Ismail-Taha>
Joe-0009 <https://github.com/Joe-0009>
