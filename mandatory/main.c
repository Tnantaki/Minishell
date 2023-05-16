#include "minishell.h"

//int	g_status;


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
	if (!tokenization(cmd_line, &(msh->tokens)))
		return (false);
	// debug_tokens(msh->tokens, "Token");//debug
	if (!expander(msh->tokens))
		return (false);
	debug_tokens(msh->tokens, "Expander");//debug
	if (!parser(msh->tokens))
		return (false);
	return (0);
}

int	main(int ac, char **av, char **sys_envp)
{
	t_msh	msh;
	(void)ac;
	(void)av;

	msh.env = ft_2d_strdup(sys_envp);
	set_env(msh.env);
	// prompt_get(&msh);
	char	*cmd_line = "ls -la| echo \" Hello How \" | echo $$ $PWD|echo $HOME> infile.txt ";
	interpreter(cmd_line, &msh);
	exit(0);
	return (0);
}
