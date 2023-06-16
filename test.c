#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void	ft_print(char *str)
{
	printf("%s\n", str);
}

int main(void)
{
	if (access("/", F_OK) == 0)
		printf("Work\n");
}