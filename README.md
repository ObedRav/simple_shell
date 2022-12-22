# Holberton School

<p align="center">
 <img src= "https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/235/shell.jpeg" width="400" height="400" />

# Simple Shell :robot:

## Introduction
This repository contains the files to simulate a basic Unix Shell with its respective commands.

## Description
This repository contains the executable files to simulate a simple Unix shell with its respective basic commands as well as some advanced ones developed by the contributors. Each functionality of the file will be commented, as well as each line of the function where its compression is not so clear to the naked eye.
In the Shell you can interact both in interactive and non-interactive mode (explanation and examples in [Modes](https://github.com/ObedRav/holbertonschool-simple_shell/edit/main/README.md#modes).


## Requeriments

* Programs and functions will be compiled with ```gcc``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` ```-pedantic``` and ```-std=gnu89```
* All files should end with a new line
* No more than 5 functions per file
* Operating System: [Ubuntu 20.04 LTS](http://releases.ubuntu.com/20.04/)
* Compiler: [GCC](https://gcc.gnu.org)
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
  * ```fstat``` (```__fxstat```)(```man 2 fstat```)
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
All the files are to be compiled on an Ubuntu 20.04 LTS machine with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

Once compiled, to start the program, run:
```./hsh```
  
To exit the program, run:
```$ exit```


## List of Files

| Function Name | Description |
|---------------- | -----------|
|[shell.h](https://github.com/ObedRav/holbertonschool-simple_shell/blob/main/shell.h)    | Declaration of all functions to be used in the shell, as well as libriaries|
|[shell.c](https://github.com/ObedRav/holbertonschool-simple_shell/blob/main/shell.c) | Principal function|
|[buildin.c](https://github.com/ObedRav/holbertonschool-simple_shell/blob/main/buildin.c) | Contains exit function, string to integer converter and buildin checker |
|[path.c](https://github.com/ObedRav/holbertonschool-simple_shell/blob/main/path.c) |Contains the functions of: global variable value, adds a new node to the end of a list, creates a linked list for path directories, and finds the path of a file name.  |
|[exec_line.c](https://github.com/ObedRav/holbertonschool-simple_shell/blob/main/exec_line.c) | Contains the functions of: splitting a string by converting it to an array, reallocating the block of memory, executing a command, and freeing the array of pointers|
|[strings.c](https://github.com/ObedRav/holbertonschool-simple_shell/blob/main/strings.c) | Contains the functions to: return a pointer in memory, concatenate three strings, write the character to standard output, count chars and print a string.|

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
