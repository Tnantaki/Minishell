#include "minishell.h"

int	err_syn(int errnum)
{
	if (errnum == 1)
		printf("msh: syntax error unclosed single quote `\''\n");
	else if (errnum == 2)
		printf("msh: syntax error unclosed double quote `\"'\n");
	else if (errnum == 3)
		printf("msh: Not interpret Parenthesis `()'\n");
	// else if (errnum == 6)
	// 	printf("msh: Not interpret Variable substitution `${}'\n");
	// else if (errnum == 7)
	// 	printf("msh: Not interpret Command substitution ``' or `$()'\n");
	// else if (errnum == 8)
	// 	printf("msh: Not interpret Arithmetic expansion `$[]' or `$(())'\n");
	return (0);
}

static int	ft_dollarlen(char *str)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	else if (str[i] == '$')// pid = $$
		i += 1;
	else if (ft_isdigit(str[i]))// position argument = $1-9
		i += 1;
	else if (ft_isenvar(str[i]))//$?, $#, $@, $-, $!, $*
		i += 1;
	else if (ft_isvar(str[i]))// _, 1-9, a-z, A-Z
		i += ft_var_len(&str[i]);
	// else if (str[i] == '{')//${} : varsub
	// 	return (err_syn(6));
	// else if (str[i] == '(')// `, $() : cmdsub
	// 	return (err_syn(7));
	// else if (ft_isarithmatic(&str[i]))// $[], $(())
	// 	return (err_syn(8));
	return (i);
}

static int	in_double_quote(char *str)
{
	int	i;
	int	len;

	i = 1;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] == '"')
			return (i + 1);
		// else if (str[i] == '`')
		// 	return (ft_err_syn(7));
		else if (str[i] == '$')
		{
			len = ft_dollarlen(str);
			if (!len)
				return (false);
			i += len;
		}
		else
			i++;
	}
	return (0);
}

static int	is_unclosed_quote(char *str)
{
	int	len;
	
	len = 0;
	if (str[len] == '\'')
	{
		len = ft_1quote_len(str);
		if (!len)
			return (err_syn(1));
	}
	else
	{
		len = in_double_quote(str);
		if (!len)
			return (err_syn(2));
	}
	return (len);
}

bool	valid_syntax(char *line)
{
	int		len;

	while (*line)
	{
		len = 0;
		while (*line && ft_isspace(*line))
			line++;
		if (!(*line))
			break ;
		else if (*line == '(' || *line == ')')
			return (err_syn(3));
		else if (ft_isquote(*line))
			len = is_unclosed_quote(line);
		else if (ft_isoptr(*line))
			len = ft_optr_len(line);
		else if (*line == '$')
			len = ft_dollarlen(line);
		else if (ft_iscmd(*line))
			len = ft_cmd_len(line);
		if (!len)
			return (false);
		else
			line += len;
	}
	return (true);
}
