#ifndef MSH_UTILS_H
# define MSH_UTILS_H

# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define EXIT_SYNTAX_ERROR 258
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_D 130

//free
char	**free2d_str(char **ptr);
char	**free2d_nstr(char **ptr, int i);
//len lexer
int		ft_1quote_len(char *str);
int		ft_2quote_len(char *str);
int		ft_optr_len(char *str);
int		ft_cmd_len(char *str);
int		ft_var_len(char *line);
//is character
bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isalnum(int c);
//is delimeter character
bool	ft_isspace(int c);
bool	ft_isquote(int c);
//is special character
bool	ft_isenvar(int c);
bool	ft_ispid(int c);
bool	ft_iscmdsub(int c);
bool	ft_isvarsub(int c);
bool	ft_isoptr(int c);
//is type string
bool	ft_iscmd(int c);
bool	ft_isvar(int c);
bool	ft_isarithmatic(char *str);
//is paser
//## String ##
//ft_strlen.c
size_t	ft_strlen(char *str);
size_t	ft_2d_strlen(char **str);
// malloc
char	*ft_strdup(char *str);
char	*ft_strndup(char *str, size_t n);
char	**ft_2d_strdup(char **str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
//exit
int	ft_err_lex(int errnum);

#endif