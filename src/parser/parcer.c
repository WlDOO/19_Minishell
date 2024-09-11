/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:27:31 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/10 21:24:53 by najeuneh         ###   ########.fr       */
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

char	*ft_path2(char **str, char *str2)
{
	int		j;
	char	*cmp;

	j = -1;
	cmp = NULL;
	if (str != NULL)
	{
		while (str[++j] != NULL)
		{
			str[j] = ft_strjoin(str[j], "/");
			str[j] = ft_strjoin(str[j], str2);
			if (access(str[j], X_OK) == 0)
			{
				cmp = ft_strdup(str[j]);
				ft_free_all(str);
				return (cmp);
			}
		}
	}
	if (access(str2, X_OK) == 0)
	{
		cmp = ft_strdup(str2);
		return (ft_free_all(str), cmp);
	}
	return (ft_free_all(str), NULL);
}

char	*ft_path(char *line, t_env *lst_env)
{
	int		i;
	char	**str;
	char	*cmp;
	char	**env;

	str = NULL;
	cmp = NULL;
	env = list_to_matrix(lst_env);
	i = ft_checkpath(env);
	if (i != -1)
	{
		str = ft_split(env[i] + 5, ':');
		if (str == NULL)
			return (NULL);
	}
	cmp = ft_path2(str, line);
	ft_free_all(env);
	return (cmp);
}

void	ft_parser(t_stack *stack, t_env *env)
{
	t_node	*node;

	node = stack->up;
	ft_checknode(stack);
	node->flag = 8;
	ft_flagcheck(node);
	while (node != NULL)
	{
		node->cmd = NULL;
		if (node->flag == 0 || node->flag == 8)
		{
			node->cmd = ft_path(node->content, env);
			if (node->cmd != NULL)
				node->flag = 8;
			if (node->flag == 8)
			{
				ft_check_full_path(node);
				while (node != NULL && node->flag != 1)
					node = node->next;
			}
		}
		if (node != NULL)
			node = node->next;
	}
	ft_parser2(stack, env);
}

void	ft_parser2(t_stack *stack, t_env *list_env)
{
	t_node	*node;

	(void)list_env;
	node = stack->up;
	while (node != NULL)
	{
		node->in = NULL;
		node->out = NULL;
		node->bultin = 0;
		ft_bultincheck(node);
		node = node->next;
	}
	ft_look_cmd(stack);
	ft_checkcmd(stack);
	heredoc(stack);
	ft_finish_node(stack, NULL, NULL, -1);
}

void	ft_finish_node(t_stack *stack, char *in, char *out, int i)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		in = NULL;
		out = NULL;
		while (node != NULL && node->content && node->flag != 1)
		{
			if (node->flag == 3 || node->flag == 4
				|| node->flag == 5 || node->flag == 6)
			{
				if (node->flag == 3)
					in = ft_strdup(node->next->content);
				else if (node->flag == 5)
					in = node->in;
				else if (node->flag == 4 || node->flag == 6)
					out = ft_strdup(node->next->content);
			}
			ft_check_next(&node);
		}
		ft_suite_node(stack, in, out, ++i);
		ft_check_next(&node);
	}
	ft_clear_all(stack);
}
