/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:25 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/30 14:02:43 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

int	verif(t_env *env, char *str)
{
	if (ft_isdigit(str[0]) == 1 || verif_not_aldigit(str) == 1)
		return (printf("minishell: export: `%s': not a valid identifier\n",
				str), 1);
	if (check_char(str, '=') == 1)
	{
		while (env != NULL)
		{
			if (ft_strcmp_before_char(str, env->attribut, '=') == 0)
			{
				env->content = ft_strchr2(str, '=');
				env->flag = 1;
				return (1);
			}
			env = env->next;
		}
	}
	while (env != NULL)
	{
		if (ft_strcmp(str, env->attribut) == 0)
		{
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	not_export(t_env *env)
{
	printf_export(env);
	g_exit_code = 0;
	return ;
}

void	ft_export_last(t_env *env, t_node *node)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	if (check_char(node->full_cmd[1], '=') == 1)
	{
		tmp->content = ft_strchr2(node->full_cmd[1], '=');
		tmp->attribut = ft_strcpy2(node->full_cmd[1], '=');
		tmp->flag = 1;
	}
	else
	{
		tmp->flag = 0;
		tmp->attribut = ft_strdup(node->full_cmd[1]);
	}
	tmp->next = NULL;
	env->next = tmp;
	env = env->next;
	g_exit_code = 0;
}

void	ft_export(t_env *env, t_node *node)
{
	if (node->full_cmd[1] == NULL)
	{
		printf_export(env);
		return ;
	}
	if (!node || verif(env, node->full_cmd[1]) == 1)
	{
		g_exit_code = 1;
		return ;
	}
	while (env->next != NULL)
		env = env->next;
	ft_export_last(env, node);
}
