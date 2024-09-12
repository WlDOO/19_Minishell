/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 22:48:21 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	printf_env(t_env *list_env)
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
	g_exit_code = 0;
}

void	printf_export(t_env *list_env)
{
	char	**matrix;
	int		i;

	i = 0;
	g_exit_code = 0;
	matrix = list_to_matrix(list_env);
	matrix = trie_asci(matrix);
	while (matrix[i])
	{
		printf("declare -x %s\n", matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
}
