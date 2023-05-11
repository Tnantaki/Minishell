#include "minishell.h"

int	checker_token(void)
{
	char *line = "ls -la| echo \" Hello How \" > infile.txt ";
	char **token = lexer(line);
	for (int i = 0; token[i]; i++)	
		printf("token[%d]:%s\n", i, token[i]);
	return (0);
}