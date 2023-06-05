#include "minishell.h"

int	g_status;

// int	prompt_get(t_msh *msh)
// {
// 	char	*cmd_line = "ls -la| echo \" Hello How \" |echo $HOME> infile.txt ";

// 	// while (true)
// 	// {
// 		// cmd_line = readline("msh: ");
// 		// add_history(cmd_line);
// 		// rl_clear_history();
// 	// }
// 	// free(cmd_line);
// 	return (0);
// }

int	interpreter(char *cmd_line, t_msh *msh)
{
	if (!valid_syntax(cmd_line))
		return (false);
	if (!tokenization(cmd_line, msh))
		return (false);
	// debug_tokens(msh->tokens, "Token");//debug
	if (!expander(msh->tokens))
		return (false);
	// debug_tokens(msh->tokens, "Expander");//debug
	if (!parser(msh))
		return (false);
	// debug_spcmd(msh->spcmd, msh->nb_cmd);
	if (!executor(msh->spcmd, msh->nb_cmd, msh->nb_pipe))
		return (false);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_msh	msh;
	char	*line;
	(void)av;

	if (ac > 1)
		return (printf("This program don't take any argument\n"), 1);
	msh.env = ft_2d_strdup(envp);
	set_env(msh.env);
	// set_signal();
	// prompt_get(&msh);
	// line = "ls -la| echo \" Hello How \" | echo $$ $PWD|echo $HOME> infile.txt ";
	while (true)
	{
		line = readline("msh: ");
		if (!line)// line is NULL because found EOF (Ctrl+D)
			exit(0);
		interpreter(line, &msh);
		// add_history(line);
		// rl_clear_history();
	}
	// free(line);
	// exit(0);
	return (0);
}
