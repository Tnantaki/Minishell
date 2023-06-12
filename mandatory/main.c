#include "minishell.h"

int	g_status;

// ### interpreter ###
// get line from main and do lexer, parser and execute

static int	interpreter(char *line, t_msh *msh)
{
	add_history(line);
	if (!valid_syntax(line))
		return (false);
	if (!tokenization(line, msh))
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

void	handler(int sig)
{
	(void)sig;
	g_status = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int ac, char **av, char **envp)
{
	struct termios term;
	t_msh	msh;
	char	*line;

	(void)av;
	if (ac > 1)
		return (printf("This program don't take any arguments\n"), 1);
	set_termios(&term);// setting for disable echo ctrl
	set_signal();
	msh.env = ft_2dstrdup(envp);
	set_env(msh.env);
	while (true)
	{
		signal(SIGINT, &sigint_handler);
		line = readline("msh :");
		if (!line)// line is NULL because found EOF (Ctrl+D)
			break ;
		if (*line)
			interpreter(line, &msh);
		free(line);
	}
	rl_clear_history();
	restore_termios(&term);
	printf("exit\n");
	return (0);
}

// line = "ls -la| echo " Hello How " | echo $$ $PWD|echo $HOME> infile.txt ";