/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:29:51 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:29:52 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

bool	ft_isvar(int c)
{
	if (c == '_' || ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}

bool	ft_is_1stvar(int c)
{
	if (c == '_' || ft_isalpha(c))
		return (true);
	return (false);
}
