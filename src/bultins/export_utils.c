/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:08:30 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/26 18:13:10 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_env_nodes(t_env *env)
{
	int	count;

	count = 0;
	while (env != NULL)
	{
		count++;
		env = env->next;
	}
	return (count);
}

void	free_matrix_export(char **matrix, int i)
{
	while (i > 0)
		free(matrix[--i]);
	free(matrix);
}

char	*allocate_matrix(t_env *env)
{
	char	*cell;

	if (env->flag == 0)
		cell = malloc(sizeof(char) * (ft_strlen(env->attribut) + 1));
	else
		cell = malloc(sizeof(char) * (ft_strlen(env->attribut)
					+ ft_strlen(env->content) + 4));
	return (cell);
}

void	fill_matrix_cell(t_env *env, char *cell)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (env->attribut[j] != '\0')
	{
		cell[j] = env->attribut[j];
		j++;
	}
	if (env->flag == 0)
		cell[j] = '\0';
	else
	{
		cell[j++] = '=';
		cell[j++] = '"';
		while (env->content[k] != '\0')
			cell[j++] = env->content[k++];
		cell[j++] = '"';
		cell[j] = '\0';
	}
}

char	**list_to_matrix(t_env *env)
{
	int		i;
	int		env_count;
	char	**matrix;

	i = 0;
	env_count = count_env_nodes(env);
	matrix = malloc(sizeof(char *) * (env_count + 1));
	if (!matrix)
		return (NULL);
	while (env != NULL)
	{
		matrix[i] = allocate_matrix(env);
		if (!matrix[i])
		{
			free_matrix_export(matrix, i);
			return (NULL);
		}
		fill_matrix_cell(env, matrix[i]);
		env = env->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
