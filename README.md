**Write  code that passes the Betty checks
**Write a simple UNIX command interpreter.
**Simple shell 0.1 +
**Simple shell 0.2 +

shell should not have any memory leaks
No more than 5 functions per file
header files should be include guarded
Use system calls only when necessary



Handle the PATH

fork must not be called if the command doesn’t exist
**Simple shell 0.4 +



Implement the env built-in, that prints the current environment
**Simple shell 0.1 +



Write your own getline function

Use a buffer to read many chars at once and call the least possible the read system call

You will need to use static variables

You are not allowed to use getline

You don’t have to:



be able to move the cursor
**Simple shell 0.2 +



You are not allowed to use strtok
**Simple shell 0.4 +



handle arguments for the built-in exit

Usage: exit status, where status is an integer used to exit the shell
**Simple shell 1.0 +



Implement the setenv and unsetenv builtin commands



setenv

Initialize a new environment variable, or modify an existing one

Command syntax: setenv VARIABLE VALUE

Should print something on stderr on failure

unsetenv

Remove an environment variable

Command syntax: unsetenv VARIABLE

Should print something on stderr on failure
