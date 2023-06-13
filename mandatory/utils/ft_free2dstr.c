/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:26:48 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:26:49 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

char	**ft_free2dstr(char **ptr)
{
	int	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}
