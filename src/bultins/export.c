/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:25 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 16:58:43 by sadegrae         ###   ########.fr       */
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

void export_dollard(t_env *env, t_node *node, int i)
{
	if (check_char(node->full_cmd[i], '=') == 1)
	{
		while (env != NULL)
		{
			if (ft_strcmp_before_char(node->full_cmd[i] + 1, env->attribut, '=') == 0)
			{
				node->full_cmd[i] = ft_strjoin_export(env->content ,ft_strchr(node->full_cmd[i], '='));
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
				return ;
			}
			env = env->next;
		}	
	}
	return ;
}

int	verif(t_env *env, char *str)
{
	if (str[0] == '$')
	{
		return (1);
	}
	if (ft_isdigit(str[0]) == 1 || verif_not_aldigit(str) == 1)
		return (printf("minishell: export: `%s': not a valid identifier\n",
				str), 1);
	if (check_sep2(str) == 0)
	{
		while (env != NULL)
		{
			if (ft_strcmp_before_char(str, env->attribut, '+') == 0)
			{
				str = ft_strchr2(str, '=');
				if (str[0] == '"')
					str = ft_strcpy2(str + 1, '"');
				env->content = ft_strjoin(env->content , str);
				env->flag = 1;
				return (1);
			}
			env = env->next;
		}
	}
	if (check_char(str, '=') == 1)
	{
		while (env != NULL)
		{
			if (ft_strcmp_before_char(str, env->attribut, '=') == 0)
			{
				env->content = ft_strchr2(str, '=');
				if (env->content[0] == '"')
					env->content = ft_strcpy2(env->content + 1, '"');
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


void	ft_export_last(t_env *env, char *node)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
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
	env = env->next;
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
		if (!node || verif(env, node->full_cmd[i]) == 1)
		{
			g_exit_code = 1;
			if (node->full_cmd[i + 1] == NULL)
				return ;
		}
		else
		{
			while (env->next != NULL)
				env = env->next;
			ft_export_last(env, node->full_cmd[i]);
		}
		i++;
	}
}
