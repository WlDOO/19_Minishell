/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:47:57 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/04 13:55:57 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_env(t_env *list_env)
{
	t_env	*tmp;

	while (list_env)
	{
		tmp = list_env->next;
		if (list_env->content)
			free (list_env->content);
		if (list_env->attribut)
			free(list_env->attribut);
		free (list_env);
		list_env = tmp;
	}
	list_env = NULL;
}
