#include "minishell.h"

char	**set_env(char **env)
{
	static char **stc_env = NULL;

	if (!env)
		return (stc_env);
	stc_env = env;
	return (stc_env);
}

char **get_env(void)
{
	return (set_env(NULL));
}
