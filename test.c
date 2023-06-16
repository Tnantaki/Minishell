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
	char *str = "\"$HOME\"";
	printf("strlen :%lu\n", strlen(str));
	char *dst = strdup("AAAAAA");
	strncpy(&dst[1], str + 1, 3);

	// strncpy(dst, str + 1, strlen(str) - 2);
	printf("%s\n", dst);
}