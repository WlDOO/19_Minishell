/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:25 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:37 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void printf_export(t_env *list_env)
{
	while (list_env != NULL)
	{
		if(list_env->flag == 1)
		{
			printf("declare -x %s=", list_env->attribut);
			printf("\"%s\"\n", list_env->content);
		}
		else
			printf("declare -x %s\n", list_env->attribut);
		list_env = list_env->next;
	}
}

void ft_export(t_env *env, t_stack *stack)
{
	t_node	*node;
	t_env *tmp;

	tmp = malloc(sizeof(t_env*));
	node = stack->up;
	node = node->next;
	while (env->next != NULL)
		env = env->next;
	if (check_egal(node->content) == 1)
	{	
		tmp->content = ft_strchr2(node->content, '=');
		tmp->attribut = ft_strcpy2(node->content, '=');
		tmp->flag = 1;
	}
	else
	{
		tmp->attribut = node->content;
		tmp->flag = 0;	
	}
	tmp->next = NULL;
	env->next = tmp;
}