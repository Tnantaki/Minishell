/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:30:27 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/13 17:30:28 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_UTILS_H
# define MSH_UTILS_H

# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

//free
char	**ft_free2dstr(char **ptr);
char	**ft_free2dnstr(char **ptr, int i);
//len lexer
int		ft_1quote_len(char *str);
int		ft_2quote_len(char *str);
int		ft_optr_len(char *str);
int		ft_cmd_len(char *str);
int		ft_var_len(char *line);
//is character
bool	ft_isspace(int c);
bool	ft_isquote(int c);
bool	ft_isspecial(int c);
bool	ft_isoptr(int c);
bool	ft_iscmd(int c);
bool	ft_isvar(int c);
bool	ft_is_1stvar(int c);
//string
void	ft_prterr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_2dstrlen(char **str);
char	*ft_strndup(char *str, size_t n);
char	**ft_2dstrdup(char **str);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_strinsert(char *str, int len_var, int i_var, char *value);

#endif
