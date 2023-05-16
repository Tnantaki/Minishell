#include "minishell.h"

int	debug_tokens(char **str, char *title)
{
	printf("%s\n", title);
	for (int i = 0; str[i]; i++)	
		printf("str[%d]:%s\n", i, str[i]);
	return (0);
}

int	debug_type(t_type *type, int ct, char *title)
{
	printf("%s\n", title);
	for (int i = 0; i < ct; i++)
	{
		printf("type[%d]: ", i);
		if (type[i] == 1)
			printf("Redirection\n");
		else if (type[i] == 2)
			printf("Pipe\n");
		else if (type[i] == 3)
			printf("Filename\n");
		else if (type[i] == 4)
			printf("Command\n");
		else if (type[i] == 5)
			printf("Argument\n");
		else
			printf("Error\n");
	}
	return (0);
}