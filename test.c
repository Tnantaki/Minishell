#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("infile", O_RDWR);
	char buf[20];
	close(3);
	read(fd, buf, 8);
	printf("%s\n", buf);
}