#include "minishell.h"

int	g_status;

int	interpreter(char *cmd_line, t_msh *msh)
{
	if (!valid_syntax(cmd_line))
		return (false);
	if (!tokenization(cmd_line, msh))
		return (false);
	// debug_tokens(msh->tokens, "Token");//debug
	if (!classify_token(msh))
		return (false);
	// debug_type(msh->tk_type, msh->nb_tk, "Type");//debug
	if (!valid_tokens(msh->tokens, msh->nb_tk, msh->tk_type))
		return (false);
	if (!expander(msh->tokens))
		return (false);
	// debug_tokens(msh->tokens, "Expander");//debug
	if (!parser(msh))
		return (false);
	// debug_spcmd(msh->spcmd, msh->nb_cmd);//debug
	if (!executor(msh->spcmd, msh->nb_cmd))
		return (false);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	struct termios	term;
	t_msh			msh;
	char			*line;

	(void)av;
	if (ac > 1)
		return (printf("This program don't take any argument\n"), 1);
	msh.env = ft_2dstrdup(envp);
	set_env(msh.env);
	// set_signal();
	set_termios(&term);
	// line = "ls -la| echo " Hello How " | echo $$ $PWD|echo $HOME> infile.txt ";
	while (true)
	{
		g_status = 0;
		line = readline(PROMPT);
		if (!line)// line is NULL because found EOF (Ctrl+D)
			break ;
		interpreter(line, &msh);
		add_history(line);
		free(line);
	}
	rl_clear_history();
	restore_termios(&term);
	printf("exit\n");
	return (0);
}
