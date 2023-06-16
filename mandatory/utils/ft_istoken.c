/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:57:03 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/15 20:57:05 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

bool	ft_istoken(int c)
{
	if (!ft_isspace(c) && !ft_isoptr(c))
		return (true);
	return (false);
}