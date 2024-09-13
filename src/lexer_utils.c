/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:39:17 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 22:00:17 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_lexer_expextion_2(char *line, int i)
{
	if (line[i] == 34)
	{
		i++;
		while (line[i] && line[i] != 34)
			i++;
		if (line[i + 1] == 34)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 34)
				i++;
		}
		else if (line[i + 1] == 39)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 39)
				i++;
		}
		if (line[i + 1] != ' ')
			while (line[i + 1] && check_sep(line[i + 1], "<>| ") == 1)
				i++;
	}
	return (i);
}

int	ft_lexer_expextion2_2(char *line, int i, int start)
{
	if (line[i] == 34)
	{
		i++;
		while (line[i] && line[i] != 34)
			i++;
		if (line[i + 1] == 34)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 34)
				i++;
		}
		else if (line[i + 1] == 39)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 39)
				i++;
		}
		if (line[i + 1] != ' ')
			while (line[i + 1] && check_sep(line[i + 1], "<>| ") == 1)
				i++;
	}
	else
		while (line[i] && line[start] == line[i + 1])
			i++;
	return (i);
}

int	ft_lexer_normal(char *line, int start, int i)
{
	while (line[i] && check_sep(line[i], "<>| ") == 1)
	{
		if (ft_lexer_expextion(line, start, i) != 0)
			i += ft_lexer_expextion(line, start, i);
		else
			i++;
	}
	return (i);
}

int	ft_lexer_verif(t_node *node)
{
	while (node != NULL)
	{
		if (verif_char_special2(node->content, node->next) == 0)
		{
			return (1);
		}
		node = node->next;
	}
	return (0);
}
