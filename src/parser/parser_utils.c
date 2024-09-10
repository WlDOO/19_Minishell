/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:43:12 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/09 17:43:36 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_all(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		free (str[i]);
	}
	free (str);
}

int	ft_checkpath(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PATH", 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bultincheck(t_node *node)
{
	node->bultin = 0;
	if (ft_strcmp(node->content, "echo") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strcmp(node->content, "cd") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strcmp(node->content, "pwd") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strcmp(node->content, "export") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else
		ft_bultincheck2(node);
}

t_node	*ft_flagcheck(t_node *node)
{
	if (node->content[0] == '|')
		node->flag = 1;
	else if (node->content[0] == '&')
		node->flag = 2;
	else if (ft_strcmp(node->content, "<<") == 0)
	{
		node->flag = 5;
	}
	else if (ft_strcmp(node->content, ">>") == 0)
		node->flag = 6;
	else if (node->content[0] == '<')
		node->flag = 3;
	else if (node->content[0] == '>')
		node->flag = 4;
	else if (node->content[0] == ' ')
		node->flag = -1;
	return (node);
}

void	ft_suite_node(t_stack *stack, char *in, char *out, int i)
{
	t_node	*node;

	node = stack->up;
	if (in == NULL && out == NULL)
		return ;
	while (node != NULL)
	{
		if (node->flag == 8)
		{
			if (i == 0)
			{
				if (in != NULL)
					node->in = ft_strdup(in);
				if (out != NULL)
					node->out = ft_strdup(out);
			}
			else
				i--;
		}
		node = node->next;
	}
	if (in != NULL)
		free (in);
	if (out != NULL)
		free (out);
}
