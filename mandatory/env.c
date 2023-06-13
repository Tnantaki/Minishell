/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:29:14 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:29:15 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_env(char **env)
{
	static char **stc_env = NULL;

	if (!env)
		return (stc_env);
	stc_env = env;
	return (stc_env);
}

char **get_env(void)
{
	return (set_env(NULL));
}
