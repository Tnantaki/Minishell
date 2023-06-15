/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:24:50 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:24:51 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ### tokenization ###
// split command line into token
// Token : be separate by 
// - White-space
// - Redirection
// - Quotes

static int	count_token(char *line)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (!line[i])
			break ;
		else if (line[i] == '\'')
			i += ft_1quote_len(&line[i]);
		else if (line[i] == '\"')
			i += ft_2quote_len(&line[i]);
		else if (ft_isoptr(line[i]))
			i += ft_optr_len(&line[i]);
		else if (ft_iscmd(line[i]))
			i += ft_cmd_len(&line[i]);
		ct++;
	}
	return (ct);
}

static char	*strcpy_inquote(char **line)
{
	char	*token;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	if (**line == '\'')
		len += ft_1quote_len(*line) - 2;
	else if (**line == '\"')
		len += ft_2quote_len(*line) - 2;
	token = (char *)malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	(*line)++;
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

static char	*strcpy_outquote(char **line)
{
	char	*token;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	if (ft_isoptr(**line))
		len += ft_optr_len(*line);
	else if (ft_iscmd(**line))
		len += ft_cmd_len(*line);
	token = (char *)malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

static char	*trim_token(char **line)
{
	char	*token;

	token = NULL;
	while (**line && ft_isspace(**line))
		(*line)++;
	if (**line == '\'' || **line == '\"')
		token = strcpy_inquote(line);
	else if (ft_isoptr(**line) || ft_iscmd(**line))
		token = strcpy_outquote(line);
	if (!token)
		return (NULL);
	return (token);
}

bool	tokenization(char *line, t_msh *msh)
{
	int		i;
	int		ct;
	char	**tokens;

	i = 0;
	ct = count_token(line);
	tokens = (char **)malloc(sizeof(char *) * (ct + 1));
	if (!tokens)
		return (false);
	while (i < ct)
	{
		tokens[i] = trim_token(&line);
		if (!tokens[i])
			return (ft_free2dnstr(tokens, i), perror("Error malloc"), false);
		i++;
	}
	tokens[i] = NULL;
	msh->tokens = tokens;
	msh->nb_tk = ct;
	return (true);
}
