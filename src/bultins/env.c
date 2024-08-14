/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:47 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void printf_env(t_env *list_env)
{
	while (list_env != NULL)
	{
		if (list_env->flag == 1)
		{
			printf("%s=", list_env->attribut);
			printf("%s\n", list_env->content);
		}
		list_env = list_env->next;
	}
}