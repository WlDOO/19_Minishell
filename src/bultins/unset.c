/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:28 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/03 16:40:06 by sadegrae         ###   ########.fr       */
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
				break ;
			}
			free(env->next);
			env->next = env->next->next;
		}
		env = env->next;
	}
	
}

void	ft_unset(t_env *env, t_node *node)
{
	t_env	*tmp;
	int		i;

	i = 1;
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
	g_exit_code = 0;
}
