#ifndef MSH_UTILS_H
# define MSH_UTILS_H

# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

// # define EXIT_SYNTAX_ERROR 258
// # define EXIT_CMD_NOT_FOUND 127
// # define EXIT_CTRL_D 130

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
bool	ft_isenvar(int c);
bool	ft_isoptr(int c);
//is type string
bool	ft_iscmd(int c);
bool	ft_isvar(int c);
// bool	ft_isarithmatic(char *str);
//## String ##
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_2dstrlen(char **str);
char	*ft_strndup(char *str, size_t n);
char	**ft_2dstrdup(char **str);
char	*ft_strjoinfree(char *s1, char *s2);
// //exit
// int	ft_err_lex(int errnum);
// void	ft_err_par(int errnum);

#endif