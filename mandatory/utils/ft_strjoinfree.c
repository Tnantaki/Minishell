/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:28:14 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:28:15 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*dst;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (lens1--)
		dst[i++] = s1[j++];
	j = 0;
	while (lens2--)
		dst[i++] = s2[j++];
	dst[i] = '\0';
	if (s1)
		free(s1);
	return (dst);
}
