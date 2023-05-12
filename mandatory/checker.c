#include "minishell.h"

int	checker_2d_arr(char **str, char *title)
{
	printf("%s\n", title);
	for (int i = 0; str[i]; i++)	
		printf("str[%d]:%s\n", i, str[i]);
	return (0);
}