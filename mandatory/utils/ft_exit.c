#include "minishell.h"

/*
errnum 6 : '$[' and '$((' is arithmetic expansion.
errnum 7 : '`' and '$(' is substitiution command.
*/

int	ft_err_lex(int errnum)
{
	if (errnum == 1)
		printf("msh: syntax error unclosed single quote `\''\n");
	else if (errnum == 2)
		printf("msh: syntax error unclosed double quote `\"'\n");
	else if (errnum == 6)
		printf("msh: Not interpret Variable substitution `${}'\n");
	else if (errnum == 7)
		printf("msh: Not interpret Command substitution ``' or `$()'\n");
	else if (errnum == 8)
		printf("msh: Not interpret Arithmetic expansion `$[]' or `$(())'\n");
	else if (errnum == 9)
		printf("msh: Not interpret Parenthesis `()'\n");
	return (0);
}

void	ft_err_par(int errnum)
{
	if (errnum == 1)
		printf("msh: syntax error near unexpected token `|'\n");
}

void	ft_err_exe(int errnum)
{
	if (errnum == 7)
		printf("Error Here Doc\n");
}


// void	free_exit(t_args *args, int code)
// {
	// if (args->pl)
	// 	free(args->pl);
	// if (args->th)
	// 	free(args->th);
	// if (args->mutex)
	// 	free(args->mutex);
	// if (args->lock)
	// 	free(args->lock);
	// if (args->fork)
	// 	free(args->fork);
	// if (code == 0)
	// 	exit(0);
	// else if (code == 1)
	// 	printf(ERR, "Error to malloc");
	// else if (code == 2)
	// 	printf(ERR, "Error to initialize mutex");
	// else if (code == 3)
	// 	printf(ERR, "Fail to create new thread");
	// else if (code == 4)
	// 	printf(ERR, "Fail to join thread");
// 	exit(1);
// }