#include "minishell.h"

static int	count_token(const char *line)
{
	int		i;
	int		ct; //count token

	i = 0;
	ct = 0;
	while (line[i])
	{
		if (line[i] && ft_isquote(line[i]))
		{
			ct++;
			while (line[++i] && !(ft_isquote(line[i])))
				;
			i++;
		}
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i] && !(ft_isquote(line[i])) && !(ft_isspace(line[i])))
		{
			ct++;
			while (line[i] && !(ft_isquote(line[i])) && !(ft_isspace(line[i])))
				i++;
		}
	}
	return (ct);
}

static char	*trim_token(char **line)
{
	char	*token;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (**line && ft_isspace(**line))//Have to check space first
		(*line)++;
	if ((*line)[i] && ft_isquote((*line)[i]))//Choose between quote or command
	{
		while ((*line)[++len] && !(ft_isquote((*line)[len])))
			;
		len++;
	}
	else
	{
		while ((*line)[len] && !(ft_isquote((*line)[len])) && !(ft_isspace((*line)[len])))
			len++;
	}
	token = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

static char	**free_token(char **token, int i)
{
	while (i >= 0)
	{
		free(token[i]);
		i--;
	}
	free(token);
	return (NULL);
}

char	**split_ws(char *line)
{
	int		i;
	int		ct;
	char	**token;

	i = 0;
	ct = count_token(line);
	token = (char **)malloc(sizeof(char *) * (ct + 1));
	if (!token)
		return (NULL);
	while (i < ct)
	{
		token[i] = trim_token(&line);
		if (!token[i])
			return (free_token(token, i));
		i++;
	}
	token[i] = NULL;
	return (token);
}

// int main(void)
// {
// 	char *line = "ls -la| echo \" Hello How \" > infile.txt ";
// 	char **token = split_ws(line);
// 	for (int i = 0; token[i]; i++)	
// 		printf("token[%d]:%s\n", i, token[i]);
// 	return (0);
// }