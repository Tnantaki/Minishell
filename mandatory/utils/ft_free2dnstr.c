/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dnstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:26:25 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:26:26 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

char	**ft_free2dnstr(char **ptr, int i)
{
	if (!ptr)
		return (NULL);
	i--;
	while (i >= 0)
	{
		free((void *)ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}
