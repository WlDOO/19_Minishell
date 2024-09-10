/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/10 19:34:24 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	strjoin_guillmet_with_str(t_env *env, int count, t_node *str)
{
	while (env != NULL)
	{
		if (ft_strcmp(str->content + 1 + count, env->attribut) == 0)
		{
			str->content = env->content;
			g_exit_code = 0;
			return ;
		}
		env = env->next;
	}
	if (check_char(str->content, '$') == 1)
		str->content = check_dollar_interrogation(str->content);
	g_exit_code = 0;
	return ;
}

void	expend_if_dollard(t_env *env, t_node *str)
{
	char	*dest;
	char	*sep;

	sep = check_sort_guillmet(str->content, -1, 0, 0);
	dest = ft_strjoin_expend(sep, ft_strcpy3(str->content + count));
	sep = check_sort_guillmet(str->content, -1, 0, 0);
	if (sep)
		sep = ft_strrev(sep);
	dest = ft_strjoin_expend(dest, sep);
	dest = check_dollar(dest, env, first_sep, 0);
	free(str->content);
	str->content = dest;
	count = count_guillmet(str->content, 0, 0);
	if (last_compare(first_sep) == 1 && (sep == NULL
			|| str->content[count - 1] == 39))
	{
		strjoin_guillmet_with_str(env, count, str);
		return ;
	}
	str->content = dest;
	g_exit_code = 0;
	return ;
}

void	expend_ifnot_dollard(t_env *env, t_node *str)
{
	if (str->content[0] != '$')
	{
		g_exit_code = 0;
		return ;
	}
	while (env != NULL)
	{
		if (ft_strcmp(str->content + 1, env->attribut) == 0)
		{
			str->content = env->content;
			g_exit_code = 0;
			return ;
		}
		env = env->next;
	}
	if (check_char(str->content, '$') == 1)
		str->content = check_dollar_interrogation(str->content);
	g_exit_code = 0;
}

void	ft_expender_suite(t_node *str, t_env *env)
{
	if (ft_strcmp(str->content, "~") == 0)
	{
		while (env != NULL)
		{
			if (ft_strcmp("HOME", env->attribut) == 0)
			{
				str->content = env->content;
				g_exit_code = 0;
				return ;
			}
			env = env->next;
		}
		str->content = ft_strdup("/Users/sadegrae");
	}
	return ;
}

void	ft_expend(t_stack *stack, t_env *env)
{
	// int		count;
	// char	*first_sep;
	t_node	*str;

	str = stack->up;
	g_exit_code = 0;
	(void)env;
	while (str)
	{
		printf("str = %s\n", str->content);

		expend_if_dollard(env, str);
		ft_split_cot(str);
		str = str->next;
	}
	return ;
}
