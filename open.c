#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	fd = open("newfile", O_RDWR | O_CREAT);
	// fd = open("file", O_RDONLY | O_CREAT);

	char buf[500];
	int readable = read(fd, buf, 20);
	printf("Amount of readable char :%d\n", readable);
	printf("Buf : %s\n", buf);
	return (0);
}

