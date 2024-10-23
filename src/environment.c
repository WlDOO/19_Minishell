/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:43:47 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 22:05:32 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_pwd(char **matrix, t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = NULL;
	while (matrix[i])
	{
		if (ft_strncmp(matrix[i], "PWD", 3) == 0)
			break ;
		i++;
	}
	if (matrix[i] == NULL)
	{
		while (env->next != NULL)
			env = env->next;
		tmp = malloc(sizeof(t_env));
		if (!tmp)
			return ;
		tmp->content = ft_strdup(getcwd(NULL, 0));
		tmp->attribut = ft_strdup("PWD");
		tmp->flag = 1;
		tmp->next = NULL;
		env->next = tmp;
	}
}

void	ft_cd_home(t_env *env)
{
	while (env != NULL)
	{
		if (ft_strcmp("HOME", env->attribut) == 0)
		{
			ft_cd_secur(env->content, NULL);
			g_exit_code = 0;
			return ;
		}
		env = env->next;
	}
	return ;
}

void	ft_look_append(t_stack	*stack, t_node *tmp)
{
	t_node	*node;

	node = stack->up;
	while (node)
	{
		tmp = node;
		while (node && node->flag != 1)
		{
			if (node->flag == 8)
			{
				while (tmp && tmp->flag != 1)
				{
					if (tmp->flag == 6)
						break ;
					tmp = tmp->next;
				}
				if (tmp != NULL
					&& ft_strcmp(node->out, tmp->next->content) == 0)
					node->append = 1;
			}
			node = node->next;
		}
		if (node != NULL)
			node = node->next;
	}
}
