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
		if (type[i] == 0)
			printf("Redirection Input\n");
		else if (type[i] == 1)
			printf("Redirection Output\n");
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

int	debug_spcmd(t_spcmd *spcmd, int cmd_nb)
{
	printf("### Simple Command ###\n");
	for (int i = 0; i < cmd_nb; i++)
	{
		printf("Cmd[%d]: %s\n", i + 1, spcmd[i].cmd);
		printf("arg");
		for (int j = 0; spcmd[i].arg[j]; j++)
			printf("[%d]: %s, ", j +1, spcmd[i].arg[j]);
		printf("\nin :%d, %d, %s\n", spcmd[i].in.have, spcmd[i].in.rdrt, spcmd[i].in.filename);
		printf("out :%d, %d, %s\n", spcmd[i].out.have, spcmd[i].out.rdrt, spcmd[i].out.filename);
		printf("pipe :%d\n", spcmd[i].pipe);
	}
	return (0);
}