#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
// # include "libft.h"

//Part 1 : Lexer
char	**lexer(char *line);
//Part 2 : Paser
int		paser(char **tokens);
char	**expander(char **tokens);
//Part 3 : Executor
//Part 4 : Built-in

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);

//### Utils ###//
//free
char	**free2d_str(char **ptr);
char	**free2d_nstr(char **ptr, int i);
//len lexer
int		quote_len(char *str);
int		optr_len(char *str);
int		cmd_len(char *str);
int		var_len(char *line);
//is lexer
bool	ft_isspace(int c);
bool	ft_isquote(int c);
bool	ft_isoptr(int c);
bool	ft_iscmd(int c);
//is paser
bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isvar(int c);
//string
size_t	ft_strlen(char *str);
size_t	ft_2d_strlen(char **str);
char	*ft_strdup(char *str);
char	**ft_2d_strdup(char **str);

//Debug
int		checker_2d_arr(char **str, char *title);

#endif