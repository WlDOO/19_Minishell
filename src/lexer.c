/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:49:55 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/14 12:32:33 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

void	lexer(t_stack *stack, char *line, char **env, int start)
{
	int		i;

	i = 0;
	if (!line)
		return;
	while (line[i])
	{
		while (line[i] && (line[i] == 32 || line[i] == '	'))
			i++;
		if (line[i] == '"' || line[i] == 39)
		{
			start = i;
			i++;
			while (line[i] && line[i] != '"')
			{
				i++;
				if (line[i] == '"' && line[i + 1] == '"')
					i += 2;
			}
			i++;
			dl_lstadd_back(stack, line, start, i);
		}
		else
			i = lexer_suite(stack, line, start, i);
	}
	ft_parser(stack, env);
	
	exec(stack, env);
}

int	lexer_suite(t_stack *stack, char *line, int start, int i)
{
	if (line[i] && check_sep(line[i], "|&<>()$`") == 1)
	{
		start = i;
		while (line[i] && check_sep(line[i], "|&<>()$` ") == 1
			&& line[i] != '"')
		{
			i++;
			if (line[i] == '"' && line[i] != 32
				&& check_sep(line[i], "|&<>()$`") == 1)
			{
				while (line[i] && line[i] != 34)
				{
					i++;
				}
				i++;
			}
		}
		dl_lstadd_back(stack, line, start, i);
	}
	else if (line[i] && check_sep(line[i], "|&<>()$`") == 0)
		i = lexer_suite2(stack, line, start, i);
	else
		i++;
	return (i);
}

int	lexer_suite2(t_stack *stack, char *line, int start, int i)
{
	start = i;
	while (line[i] && check_sep(line[i], "|&<>()$`") == 0 && line[i] != '"')
		i++;
	dl_lstadd_back(stack, line, start, i);
	return (i);
}
