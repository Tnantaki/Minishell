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

bool	buin_execution(t_buin buin, char **arg)
{
	// t_buin_cmd buin_cmd;

	if (buin == e_echo)
		g_status = ft_echo(arg);
	else if (buin == e_cd)
		g_status = ft_cd(arg);
	else if (buin == e_pwd)
		g_status = ft_pwd();
	else if (buin == e_export)
		g_status = ft_export();
	// else if (buin == e_unset)
	// 	g_status = ft_unset(arg, &buin_cmd);
	else if (buin == e_env)
		g_status = ft_env();
	return (true);
}