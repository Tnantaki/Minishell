#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_print(char *str)
{
	printf("%s\n", str);
}

int main(void)
{
	char *str = "$HOME\"";
	printf("%s\n", str);
	ft_print(str);
}