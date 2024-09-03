/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/03 15:12:23 by najeuneh         ###   ########.fr       */
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

void	expend_if_dollard(t_env *env, t_node *str, char *first_sep, int count)
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
	if (last_compare(first_sep) == 1
		&& (sep == NULL || str->content[count - 1] == 39))
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

void	expend_verif(t_env *env, int count, t_node *str, char *first_sep)
{
	if (count == -2)
	{
		g_exit_code = 0;
		return ;
	}
	if (count == -1)
	{
		if (check_char(str->content, '=') == 1)
			return ;
		printf("minishell: syntax error: unexpected end of file\n");
		g_exit_code = 1;
		return ;
	}
	if (count != 0)
	{
		expend_if_dollard(env, str, first_sep, count);
	}
	else
	{
		expend_ifnot_dollard(env, str);
	}
}

void	ft_expend(t_stack *stack, t_env *env)
{
	int		count;
	char	*first_sep;
	t_node	*str;

	if (stack->up->next == NULL)
		return ;
	str = stack->up;
	str = str->next;
	if (verif_char_special(str->content, str->next) == 0)
		return ;
	count = count_guillmet(str->content, 0, 0);
	first_sep = check_first_sep(str->content);
	expend_verif(env, count, str, first_sep);
	g_exit_code = 0;
	return ;
}
