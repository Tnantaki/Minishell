/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:52:15 by prachman          #+#    #+#             */
/*   Updated: 2023/06/09 13:59:26 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(void)
{
	char	*cwd;
	
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
		return (perror("error:"), EXIT_FAILURE);
	printf("%s\n", cwd);
	free(cwd);
	return (EXIT_SUCCESS);
}
