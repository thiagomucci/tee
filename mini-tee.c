#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 4096

int
main(int argc, char *argv[])
{
    int n;
    char buf[MAX_BUF];
    if(argc != 3)
    {
        write(STDOUT_FILENO,
            "try: ./prog [-a] <file>\n",
                sizeof("try: <program> <file>\n") -1);
                exit(1);
    }

	int flags =  O_WRONLY | O_CREAT;

	if((strcmp(argv[1], "-a") == 0))
	{
	flags |= O_APPEND;
	}
	else
	{
		flags |= O_TRUNC;
	}

    int fd = open(argv[2], flags, 0644);
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
    
    if(close(fd) < 0)
    {
        perror("close");
        exit(1);
    }
	return 0;
}
