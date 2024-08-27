/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:43:12 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/27 18:32:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free (str[i]);
		i++;
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
	if (ft_strncmp(node->content, "echo", 4) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "cd", 2) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "pwd", 3) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "export", 6) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "unset", 5) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "env", 3) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "exit", 4) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
}

t_node	*ft_flagcheck(t_node *node)
{
	if (node->content[0] == '|')
		node->flag = 1;
	else if (node->content[0] == '&')
		node->flag = 2;
	else if (ft_strcmp(node->content, "<<") == 0
		|| ft_strcmp(node->prev->content, "<<") == 0)
	{
		node->flag = 5;
	}
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
	while (node != NULL)
	{
		if (node->flag == 8)
		{
			if (i == 0)
			{
				if (in != NULL)
					node->in = ft_strdup(in);
				node->out = ft_strdup(out);
			}
			else
				i--;
		}
		node = node->next;
	}
}
