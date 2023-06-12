#include "minishell.h"

int	debug_tokens(char **str, char *title)
{
	printf("%s\n", title);
	for (int i = 0; str[i]; i++)	
		printf("str[%d]:%s\n", i, str[i]);
	return (0);
}

int	debug_type(t_type *type, int nb_tk, char *title)
{
	printf("%s\n", title);
	for (int i = 0; i < nb_tk; i++)
	{
		printf("type[%d]: ", i);
		if (type[i] == 1)
			printf("Redirection\n");
		else if (type[i] == 2)
			printf("Pipe\n");
		else if (type[i] == 3)
			printf("Filename\n");
		else if (type[i] == 4)
			printf("Argument\n");
		else
			printf("Error\n");
	}
	return (0);
}

int	debug_spcmd(t_spcmd *spcmd, int nb_cmd)
{
	printf("### Simple Command ###\n");
	for (int i = 0; i < nb_cmd; i++)
	{
		printf("arg:%d, io:%d, pipe:%d\n",
			spcmd[i].nb.arg, spcmd[i].nb.io, spcmd[i].nb.pipe);
		printf("arg: ");
		for (int j = 0; spcmd[i].arg[j]; j++)
			printf("%s, ", spcmd[i].arg[j]);
		printf("\n");
	}
	return (0);
}