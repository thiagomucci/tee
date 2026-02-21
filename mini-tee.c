#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#define MAX_BUF 4096

int
main(int argc, char *argv[])
{
    int n;
    char buf[MAX_BUF];
    if(argc != 2)
    {
        write(STDOUT_FILENO,
            "try: <program> <file>\n",
                sizeof("try: <program> <file>\n") -1);
                exit(1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd < 0)
    {
        perror("open file");
        exit(1);
    }
    
    while((n = read(STDIN_FILENO, buf, MAX_BUF)) > 0)
    {
        if(write(fd, buf, n) != n)
        {
            perror("write file");
            exit(1);
        }
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            perror("write output");
            exit(1);
        }
    }

    if(n < 0)
    {
        perror("read");
        exit(1);
    }
    close(fd);

}