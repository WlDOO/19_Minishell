/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:28 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 22:14:49 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	find_env(t_env *env, char *str)
{
	while (env->next != NULL)
	{
		if (ft_strcmp(str, env->next->attribut) == 0)
		{
			if (env->next->next == NULL)
			{
				env->next = NULL;
				g_exit_code = 0;
				break ;
			}
			free(env->next);
			env->next = env->next->next;
			g_exit_code = 0;
		}
		env = env->next;
	}
	g_exit_code = 1;
	return ;
}

void	ft_unset(t_env *env, t_node *node)
{
	t_env	*tmp;
	int		i;

	i = 1;
	if (node->full_cmd[1] == NULL)
		return ;
	if (node->full_cmd[1][0] == '_')
		return ;
	if (ft_strcmp(node->full_cmd[1], env->attribut) == 0)
	{
		tmp = env->next;
		*env = *tmp;
	}
	while (node->full_cmd[i])
	{
		find_env(env, node->full_cmd[i]);
		i++;
	}
}
