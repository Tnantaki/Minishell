/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:16:43 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/21 15:16:45 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_built_in(char *cmd, t_buin *buin)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (*buin = e_echo, true);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (*buin = e_cd, true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (*buin = e_pwd, true);
	else if (ft_strcmp(cmd, "export") == 0)
		return (*buin = e_export, true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (*buin = e_unset, true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (*buin = e_env, true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (*buin = e_exit, true);
	else
		return (false);
}

bool	find_buin(t_buin buin, char **arg, t_msh *msh)
{
	if (buin == e_echo)
		g_status = ft_echo(arg);
	else if (buin == e_cd)
		g_status = ft_cd(arg);
	else if (buin == e_pwd)
		g_status = ft_pwd();
	else if (buin == e_export)
		g_status = ft_export(arg);
	else if (buin == e_unset)
		g_status = ft_unset(arg);
	else if (buin == e_env)
		g_status = ft_env();
	else if (buin == e_exit)
		g_status = ft_exit(arg, msh);
	return (true);
}

bool	buin_execution(char **arg, t_pipe *px, t_msh *msh)
{
	if (msh->nb_pipe)
	{
		px->pid[px->i] = fork();
		if (px->pid[px->i] == -1)
			return (perror("Fork Fail"), false);
		if (px->pid[px->i] == 0)
		{
			free(px->pid);
			if (px->pipeout)
			{
				// dprintf(2, "clo pipe :%d\n", px->pipefd[0]);//debug
				close(px->pipefd[0]);
			}
			redirection(px);
			find_buin(px->buin, arg, msh);
			exit(g_status);
		}
	}
	else
	{
		redirection(px);
		find_buin(px->buin, arg, msh);
	}
	return (true);
}
