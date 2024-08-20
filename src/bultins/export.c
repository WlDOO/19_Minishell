/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:25 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/20 14:59:28 by najeuneh         ###   ########.fr       */
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

int	verif(t_env *env, char *str)
{
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

char	**list_to_matrix(t_env *env)
{
	char **matrix;
	int	i;
	int	j;
	int	k;
	t_env *current;
	int	env_count;

	k = 0;
	j = 0;
	i = 0;
	env_count = 0;
	current = env;
	while (current != NULL)
	{
		env_count++;
		current = current->next;
	}
	matrix = malloc(sizeof(char *) * (env_count + 1));
	if (!matrix)
		return NULL;
	while (env != NULL)
	{
		if (env->flag == 0)
			matrix[i] = malloc(sizeof(char) * (ft_strlen(env->attribut) + 1));
		else
			matrix[i] = malloc(sizeof(char) * (ft_strlen(env->attribut) + ft_strlen(env->content) + 4));
		if (!matrix[i])
		{
			while (i > 0)
				free(matrix[--i]);
			free(matrix);
			return NULL;
		}
		while (env->attribut[j] != '\0')
		{
			matrix[i][j] = env->attribut[j];
			j++;
		}
		if (env->flag == 0)
		{
			matrix[i][j] = '\0';
		}
		while (env->flag == 1 && env->content[k] != '\0')
		{
			if (k == 0)
			{
				matrix[i][j] = '=';
				j++;
				matrix[i][j] = '"';
				j++;
			}
			matrix[i][j] = env->content[k];
			j++;
			k++;
			if (env->content[k] == '\0')
			{
				matrix[i][j] = '"';
				j++;
				matrix[i][j] = '\0';
			}
		}
		env = env->next;
		i++;
		k = 0;
		j = 0;
	}
	//printf("\n\n\n\ncou\n\n");
	matrix[i] = NULL;
	return (matrix);
}

char	*add_one_line_to_matrix(char *str, char *str2, int flag)
{
	char *matrix;
	int	i;
	int j;
	
	i = 0;
	j = 0;
	if (flag == 0)
	{
		matrix = malloc(sizeof(char) * (ft_strlen(str2) + 1));
		while (str2[i] != '\0')
		{
			matrix[i] = str2[i];
			i++;
		}
		matrix[i] = '\0';
		return (matrix);
	}
	matrix = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str2) + 4));
	while (str2[i] != '\0')
	{
		matrix[i] = str2[i];
		i++;
	}
	while (str[j] != '\0')
	{
		if (j == 0)
		{
			matrix[i]= '=';
			i++;
			matrix[i] = '"';
			i++;
		}
		matrix[i] = str[j];
		j++;
		i++;
		if (str[j] == '\0')
		{
			matrix[i] = '"';
			i++;
			matrix[i] = '\0';
		}
	}
	return (matrix);
}


void ft_export(t_env *env, t_node *node)
{
	t_env *tmp;
	// char **matrix;

	//matrix = list_to_matrix(env);
	if (node->full_cmd[1] == NULL)
	{
		printf_export(env);
		return ;
	}
	if (!node)
	{
		return ;	
	}
	if (verif(env, node->content) == 1)
	{
		return ;
	}
	while (env->next != NULL)
		env = env->next;
	tmp = malloc(sizeof(t_env*));	if (check_char(node->content, '=') == 1)
	{	
		tmp->content = ft_strchr2(node->content, '=');
		tmp->attribut = ft_strcpy2(node->content, '=');
		tmp->flag = 1;
	}
	else
	{
		tmp->attribut = ft_strdup(node->content);
		tmp->flag = 0;	
	}
	tmp->next = NULL;
	env->next = tmp;
	env = env->next;
}
