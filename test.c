#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str;
	while (1)
	{
		str = malloc(1000);
		if (!str)
			perror("Error malloc");
	}

}
