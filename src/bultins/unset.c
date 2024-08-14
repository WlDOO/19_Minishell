/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:28 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:43 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset(t_env *env, t_stack *stack)
{
	t_node	*node;
	t_env	*tmp;

	node = stack->up;
	node = node->next;
	if (ft_strcmp(node->content, env->attribut) == 0)
	{
		tmp = env->next;
		*env = *tmp;
	}
	while (env->next != NULL)
	{
		if (ft_strcmp(node->content, env->next->attribut) == 0)
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