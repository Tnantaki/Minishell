#include "minishell.h"

//int	g_status;

int	prompt_get(t_msh *msh)
{
	char	*cmd_line = "ls -la| echo \" Hello How \" |echo $HOME> infile.txt ";

	while (true)
	{
		// cmd_line = readline("msh: ");
		// add_history(cmd_line);
		if (cmd_line)
		{
			if (lexer(cmd_line, msh) == true)
			{
			// if (parser(cmd_line) == false)
					// executor(cmd_line);
			}
			checker_2d_arr(msh->tokens, "Token");
			exit(0);
		}
		// rl_clear_history();
	}
	free(cmd_line);
	return (0);
}

int	main(int ac, char **av, char **sys_envp)
{
	t_msh	msh;
	(void)ac;
	(void)av;

	msh.env = ft_2d_strdup(sys_envp);
	set_env(msh.env);
	prompt_get(&msh);
	return (0);
}
