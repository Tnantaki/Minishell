#include "minishell.h"

//return 0 : on success, return 1 : on error
int	prompt_get()
{
	// char	*cmd_line;
	char	*cmd_line = "ls -la| echo \" Hello How \" > infile.txt ";
	char	**tokens;

	while (1)
	{
		// cmd_line = readline("msh: ");
		// add_history(cmd_line);
		tokens = lexer(cmd_line);
		checker_2d_arr(tokens, "Token");//for checking
		// paser(token);
		return (1);

		// rl_clear_history();
	}
	free(cmd_line);
	return (0);
}

int	main(int ac, char **av, char **sys_envp)
{
	// char	**envp;
	(void)ac;
	(void)av;
	printf("Set out minishell\n");
	checker_2d_arr(sys_envp, "System Environment");//for checking
	// envp = dup_envp(sys_envp);
	

	prompt_get();

	return (0);
}
