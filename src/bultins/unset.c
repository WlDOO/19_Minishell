/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:28 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/20 14:21:12 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset(t_env *env, t_node *node)
{
	t_env	*tmp;

	if (ft_strcmp(node->full_cmd[1], env->attribut) == 0)
	{
		tmp = env->next;
		*env = *tmp;
	}
	while (env->next != NULL)
	{
		if (ft_strcmp(node->full_cmd[1], env->next->attribut) == 0)
		{
			if (env->next->next == NULL)
			{
				env->next = NULL;
				break;
			}
			free(env->next);
			env->next = env->next->next;
		}
		env = env->next;
	}
}