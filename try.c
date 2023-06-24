#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int fd = STDIN_FILENO;
	close(fd);

	if (!isatty(-1))
		printf("stdin be closed\n");
	printf("%d\n", STDIN_FILENO);
	close(STDIN_FILENO);
}