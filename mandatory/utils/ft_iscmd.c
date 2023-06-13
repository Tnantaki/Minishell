/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:27:04 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:27:05 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_utils.h"

bool	ft_iscmd(int c)
{
	if (!ft_isspace(c) && !ft_isquote(c) && !ft_isoptr(c))
		return (true);
	return (false);
}
