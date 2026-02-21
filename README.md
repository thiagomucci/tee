# mini-tee
Thias project is a minimal implementation of the Unix program "tee" using POSIX system calls, and it is also part of a personal study of the book Advanced Programming in the UNIX Environment (APUE)
# Definition
Write input in the selected file and write in the terminal, using open, read and write
# Build
cc -Wall -Wextra -pedantic mini-tee.c -o mini-tee
# Usage
./mini-tee <file>
# References
W. Richard Stevens, Advanced Programming in the UNIX Environment
