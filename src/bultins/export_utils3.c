/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:31:28 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/11 21:24:39 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	verif_suite3(t_env *env, char *str)
{
	t_env	*tmp;

	if (ft_strcmp_before_char(str, env->attribut, '+') == 0)
	{
		str = ft_strchr2(str, '=');
		if (str[0] == '"')
			str = ft_strcpy2(str + 1, '"');
		env->content = ft_strjoin(env->content, str);
		env->flag = 1;
		return ;
	}
	str = ft_strjoin(ft_strcpy2(str, '+'), ft_strchr2(str, '+'));
	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	tmp->content = ft_strchr2(str, '=');
	tmp->attribut = ft_strcpy2(str, '=');
	tmp->flag = 1;
	tmp->next = NULL;
	env->next = tmp;
	g_exit_code = 0;
	return ;
}

void	verif_suite(t_env *env, char *str)
{
	while (env->next != NULL)
	{
		if (ft_strcmp_before_char(str, env->attribut, '+') == 0)
		{
			str = ft_strchr2(str, '=');
			if (str[0] == '"')
				str = ft_strcpy2(str + 1, '"');
			env->content = ft_strjoin(env->content, str);
			env->flag = 1;
			return ;
		}
		env = env->next;
	}
	verif_suite3(env, str);
}

int	verif_suite_2(t_env *env, char *str)
{
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

int	verif(t_env *env, char *str)
{
	if (str[0] == '$')
		return (1);
	if (str[0] == '=' && (!str[1] || str[1] == ' '))
	{
		g_exit_code = 1;
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(str, 2);
		return (ft_putstr_fd(" : not a valid identifier\n", 2), 1);
	}
	if (ft_isdigit(str[0]) == 1 || verif_not_aldigit(str) == 1)
	{
		g_exit_code = 1;
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(str, 2);
		return (ft_putstr_fd(" : not a valid identifier\n", 2), 1);
	}
	if (check_sep2(str) == 0)
	{
		verif_suite(env, str);
		return (1);
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
		return (0);
	}
	
	// while (env != NULL)
	// {
	// 	if (ft_strcmp(str, env->attribut) == 0)
	// 		return (1);
	// 	env = env->next;
	// }
	return (0);
}

void	not_export(t_env *env)
{
	printf_export(env);
	g_exit_code = 0;
	return ;
}
