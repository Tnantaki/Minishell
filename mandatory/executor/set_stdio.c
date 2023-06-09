#include "minishell.h"

bool	save_stdio(t_pipe *px)
{
	px->stdin = dup(STDIN_FILENO);
	px->stdout = dup(STDOUT_FILENO);
	return (true);
}

bool	restore_stdio(t_pipe *px)
{
	if (!isatty(STDIN_FILENO))
		dup2(px->stdin, STDIN_FILENO);
	if (!isatty(STDOUT_FILENO))
		dup2(px->stdout, STDOUT_FILENO);
	return (true);
}

bool	close_stdio(t_pipe *px)
{
	close(px->stdin);
	close(px->stdout);
	return (true);
}