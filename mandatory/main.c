/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:28:58 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:28:59 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ### interpreter ###
// get line from main and do lexer, parser and execute
void	free_msh(t_msh *msh)
{
	if (msh->tokens)
		ft_free2dstr(msh->tokens);
	if (msh->tk_type)
		free(msh->tk_type);
	if (msh->spcmd)
		free_spcmd(msh->spcmd, msh->nb_cmd);
	msh->tokens = NULL;
	msh->tk_type = NULL;
	msh->spcmd = NULL;
}

bool	init_msh(t_msh *msh, struct termios *term, char **envp)
{
	g_status = 0;
	msh->env = NULL;
	msh->tokens = NULL;
	msh->tk_type = NULL;
	msh->spcmd = NULL;
	(void)term;
	// set_termios(term);
	set_signal();
	// (void)envp;
	msh->env = ft_2dstrdup(envp);
	set_env(msh->env);
	return (true);
}

static bool	interpreter(char *line, t_msh *msh)
{
	add_history(line);
	if (!valid_syntax(line))
		return (false);
	if (!tokenization(line, msh))
		return (false);
	// debug_tokens(msh->tokens);//debug
	if (!classify_token(msh))
		return (false);
	// debug_type(msh->tk_type, msh->nb_tk);//debug
	if (!valid_tokens(msh->tokens, msh->nb_tk, msh->tk_type))
		return (false);
	if (!expander(msh->tokens))
		return (false);
	// debug_tokens(msh->tokens);//debug
	if (!trim_quote(msh->tokens))
		return (false);
	// debug_tokens(msh->tokens);//debug
	if (!parser(msh))
		return (false);
	// debug_spcmd(msh->spcmd, msh->nb_cmd);//debug
	if (!executor(msh->spcmd, msh->nb_cmd))
		return (false);
	free_msh(msh);
	return (true);
}

int	main(int ac, char **av, char **envp)
{
	struct termios	term;
	t_msh			msh;
	char			*line;

	(void)av;
	if (ac > 1)
		return (printf("This program don't take any arguments\n"), 1);
	if (!init_msh(&msh, &term, envp))
		return (1);
	while (true)
	{
		signal(SIGINT, &sigint_handler);
		line = readline("msh :");
		if (!line) //line is NULL because found EOF (Ctrl+D)
			break ;
		if (*line && !interpreter(line, &msh))
			free_msh(&msh);
		free(line);
	}
	rl_clear_history();
	// restore_termios(&term);
	printf("Exit\n");
	return (0);
}

//ls -la| echo " Hello How " | echo $$ $PWD|echo $HOME> infile.txt
