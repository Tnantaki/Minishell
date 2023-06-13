/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:22:11 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 15:22:18 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

void	ft_prterr(char *str)
{
	if (!str)
		return ;
	write(STDERR_FILENO, str, ft_strlen(str));
}
