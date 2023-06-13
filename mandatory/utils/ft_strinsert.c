/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:28:05 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:28:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

// function will remove Variable string and replace with Value string.
// str : String that have Variable string in it.
// var : Variable string.
// i_var : first index of var in string.
// value : Value string.
// - In case of value = NULL it be replace by empty string

char	*ft_strinsert(char *str, int len_var, int i_var, char *value)
{
	int		i;
	int		j;
	int		len_value;
	char	*new;

	if (!value)
		value = "";
	len_value = ft_strlen(value);
	new = malloc(sizeof(char) * (ft_strlen(str) - len_var + len_value + 1));
	if (!new)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (i < i_var)
		new[i++] = str[j++];
	while (*value)
		new[i++] = *value++;
	j += len_var;
	while (str[j])
		new[i++] = str[j++];
	new[i] = '\0';
	return (free(str), new);
}
