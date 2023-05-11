#include "minishell.h"

//return 0 : on success, return 1 : on error
int	prompt_get()
{
	char	*cmd_line;
	// char	**token;

	while (1)
	{
		cmd_line = readline("msh: ");
		// add_history(cmd_line);
		printf("You entered: %s\n", cmd_line);// for checking
		// token = split_ws(cmd_line);
		// for (int i = 0; token[i]; i++)// for checking
		// 	printf("%s\n", token[i]);// for checking
		// rl_clear_history(); // Clear the history list
	}
	free(cmd_line);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	printf("Set out minishell\n");
	checker_token();

	// prompt_get();

	return (0);
}
