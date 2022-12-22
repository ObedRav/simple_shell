# Holberton School

<p align="center">
 <img src= "https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/235/shell.jpeg" width="400" height="400" />

# Simple Shell :robot:

## Introduction
This repository contains the files to simulate a basic Unix Shell with its respective commands.

## Description
It is a UNIX command language interpreter, which reads commands from interactive mode and non-interactive mode.


## Requeriments

* Programs and functions will be compiled with ```gcc 4.8.4``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` ```and -pedantic```
* All files should end with a new line
* No more than 5 functions per file
* Operating System: [Ubuntu 20.04 LTS](http://releases.ubuntu.com/20.04/)
* Compiler: [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/)
* Authorized functions and system calls:
  * ```access``` (```man 2 access```)
  * ```chdir``` (```man 2 chdir```)
  * ```close``` (```man 2 close```)
  * ```closedir``` (```man 3 closedir```)
  * ```execve``` (```man 2 execve```)
  * ```exit``` (```man 3 exit```)
  * ```fork``` (```man 2 fork```)
  * ```free``` (```man 3 free```)
  * ```stat``` (```__xstat```)(```man 2 stat```)
  * ```lstat``` (```__lxstat```)(```man 2 lstat```)
  * ```fstat``` (```__fxstat)(```man 2 fstat```)
  * ```getcwd``` (```man 3 getcwd```)
  * ```getline``` (```man 3 getline```)
  * ```kill``` (```man 2 kill```)
  * ```malloc``` (```man 3 malloc```)
  * ```open``` (```man 2 open```)
  * ```opendir``` (```man 3 opendir```)
  * ```perror``` (```man 3 perror```)
  * ```read``` (```man 2 read```)
  * ```readdir``` (```man 3 readdir```)
  * ```signal``` (```man 2 signal```)
  * ```strtok``` (```man 3 strtok```)
  * ```wait``` (```man 2 wait```)
  * ```waitpid``` (```man 2 waitpid```)
  * ```wait3``` (```man 2 wait3```)
  * ```wait4``` (```man 2 wait4```)
  * ```write``` (```man 2 write```)
  * ```_exit``` (```man 2 _exit```)
  * ```isatty``` (```man 3 isatty```)
  * ```fflush``` (```man 3 fflush```)

## Flowchart
Below you can see the flowchart, which was taken as a starting point to carry out the code and each of its functionalities
![flowchar]()


## Usage :computer:
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Once compiled, to start the program, run:
```./hsh```
  
To exit the program, run:
```$ exit```


## List of functions

| Function Name | Description |
|---------------- | -----------|
|[shell.h](./shell.h)    | Declaration of all functions to be used in the shell, as well as libriaries|
|[shell.c](./shell.c) | Prints the current environment.|
|[buildin.c](./buildin.c) | Stores whatever is passed to it as standard input. |
|[path.c](./path.c) | Stores whatever is passed to it as standard input. |
|[exec_line.c](./exec_line.c) | Stores whatever is passed to it as standard input. |
|[strings.c](./strings.c) | Stores whatever is passed to it as standard input. |

## Modes
The user can have the experience in an interactive and non-interactive way.

To use the **interactive mode** use . Immediately the user will see a warning $ indicating that our shell is ready to read the command.
And to exit the program, use the word  ```exit```.
Example:
```
$ ./hsh
$ /bin/ls
```

En **non-interactive mode** the user will enter command line arguments,In non-interactive mode, you can pipe commands to the program using echo or cat:

Example:
```
$ echo "/bin/ls" | ./hsh
$ cat file_name | ./hsh
```

## Bugs
No known bugs.


## Authors
* **Obed Rayo** [Github]()
* **Maria Jose Murillo R.** [Github]()
