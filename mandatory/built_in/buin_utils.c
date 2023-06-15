/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buin_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:42:38 by prachman          #+#    #+#             */
/*   Updated: 2023/06/09 21:04:41 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*dst;
// 	size_t	i;
// 	size_t	lens;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	lens = ft_strlen(s);
// 	if (start >= lens)
// 		return ((char *)ft_calloc(1, sizeof(char)));
// 	if (lens - start < len)
// 		len = lens - start;
// 	dst = malloc(sizeof(char) * (len + 1));
// 	if (!dst)
// 		return (NULL);
// 	while (s[start + i] && i < len)
// 	{
// 		dst[i] = s[start + i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }