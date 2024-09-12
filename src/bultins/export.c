/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:25 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 21:03:09 by sadegrae         ###   ########.fr       */
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

char	check_sep2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '+' && str[i + 1] == '=')
			return (0);
		i++;
	}
	return (1);
}

char	check_sep_neg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '-' && str[i + 1] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	export_dollard(t_env *env, t_node *node, int i)
{
	if (check_char(node->full_cmd[i], '=') == 1)
	{
		while (env != NULL)
		{
			if (ft_strcmp_before_char(node->full_cmd[i] + 1, env->attribut,
					'=') == 0)
			{
				node->full_cmd[i] = ft_strjoin_export(env->content,
						ft_strchr(node->full_cmd[i], '='));
				return ;
			}
			env = env->next;
		}
	}
	else
	{
		while (env != NULL)
		{
			if (ft_strcmp(node->full_cmd[i] + 1, env->attribut) == 0)
			{
				node->full_cmd[i] = ft_strdup(env->attribut);
			}
			env = env->next;
		}
	}
}

void	ft_export_last(t_env *env, char *node)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	tmp->content = NULL;
	tmp->attribut = NULL;
	if (check_char(node, '=') == 1)
	{
		tmp->content = ft_strchr2(node, '=');
		if (tmp->content[0] == '"')
			tmp->content = ft_strcpy2(tmp->content + 1, '"');
		tmp->attribut = ft_strcpy2(node, '=');
		tmp->flag = 1;
	}
	else
	{
		tmp->flag = 0;
		tmp->attribut = ft_strdup(node);
	}
	tmp->next = NULL;
	env->next = tmp;
	g_exit_code = 0;
}

void	ft_export(t_env *env, t_node *node, int i)
{
	if (node->full_cmd[1] == NULL)
	{
		printf_export(env);
		return ;
	}
	while (node->full_cmd[i] != NULL)
	{
		if (node->full_cmd[i][0] == '$')
		{
			export_dollard(env, node, i);
		}
		if (!node || verif(env, node->full_cmd[i]) >= 1)
		{
			
			if (node->full_cmd[i + 1] == NULL)
				return ;
		}
		else
		{
			if (verif_suite_2(env, node->full_cmd[i]) == 0)
			{
				while (env->next != NULL)
					env = env->next;
				ft_export_last(env, node->full_cmd[i]);
			}
		}
		i++;
	}
}
