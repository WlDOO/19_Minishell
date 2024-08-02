/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:27:31 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/02 14:16:08 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
flag 0 = word
flag 1 = |
flag 2 = &
flag 3 = <
flag 4 = >
flag 5 = (
flag 6 = )
flag 7 = $
flag 8 = cmd
*/

t_node	*ft_flagcheck(t_node *node)
{
	if (node->content[0] == '|')
		node->flag = 1;
	else if (node->content[0] == '&')
		node->flag = 2;
	else if (node->content[0] == '<')
		node->flag = 3;
	else if (node->content[0] == '>')
		node->flag = 4;
	else if (node->content[0] == '(')
		node->flag = 5;
	else if (node->content[0] == ')')
		node->flag = 6;
	else if (node->content[0] == '$')
		node->flag = 7;
	else if (node->content[0] == ' ')
		node->flag = -1;
	return (node);
}


char	*ft_path2(char **str, char *str2)
{
	int		j;
	char	*cmp;

	j = -1;
	cmp = NULL;
	while (str[++j] != NULL)
	{
		str[j] = ft_strjoin(str[j], "/");
		str[j] = ft_strjoin(str[j], str2);
		if (access(str[j], F_OK | X_OK) == 0)
		{
			cmp = ft_strdup(str[j]);
			ft_free_all(str);
			return (cmp);
		}
	}
	return (ft_free_all(str), NULL);
}

char	*ft_path(char *line, char **env)
{
	int		i;
	char	**str;
	char	*cmp;

	cmp = NULL;
	if (access(line, F_OK | X_OK) == 0)
	{
		cmp = ft_strdup(line);
		return (cmp);
	}
	i = ft_checkpath(env);
	if (i == -1)
		return (0);
	str = ft_split(env[i] + 5, ':');
	if (str == NULL)
		return (NULL);
	cmp = ft_path2(str, line);
	return (cmp);
}

void	ft_parser(t_stack *stack, char **env)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		node->flag = 0;
		if (check_sep(node->content[0], "|&<>()$`") == 0)
			node = ft_flagcheck(node);
		node = node->next;
	}
	node = stack->up;
	while (node != NULL)
	{
		node->cmd = NULL;
		if (node->flag == 0)
		{
			node->cmd = ft_path(node->content, env);
			if (node->cmd != NULL)
				node->flag = 8;
		}
		node = node->next;
	}
	ft_parser2(stack);
}

void	ft_parser2(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 8)
			ft_bultincheck(node);
		node = node->next;
	}
}

