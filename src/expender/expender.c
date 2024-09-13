/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/13 15:06:57 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_quote_not_open_suite(t_node *str, int i, char c)
{
	i++;
	if (!str->content[i])
	{
		g_exit_code = -1;
		return (0);
	}
	while (str->content[i] && str->content[i] != c)
	{
		i++;
		if (!str->content[i])
		{
			g_exit_code = -1;
			return (0);
		}
	}
	i++;
	return (i);
}

int	check_quote_not_open(t_node *str)
{
	int	i;

	i = 0;
	while (str->content[i])
	{
		if (str->content[i] == '"')
		{
			i = check_quote_not_open_suite(str, i, '"');
			if (i == 0)
				return (0);
		}
		else if (str->content[i] == 39)
		{
			i = check_quote_not_open_suite(str, i, 39);
			if (i == 0)
				return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}

int	empty_dollard_first_place(t_env *env, char *str)
{
	while (env)
	{
		if (ft_strcmp(str + 1, env->attribut) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

void	expend_suite(t_node *str, t_env *env)
{
	if (check_if_dollard(str->content) == 1)
		if_or_not_convert(str, env, 0);
	ft_split_cot(str);
}

void	ft_expend(t_stack *stack, t_env *env)
{
	t_node	*str;

	str = stack->up;
	if (str->content[0] == '$')
	{
		if (empty_dollard_first_place(env, str->content) == 0)
		{
			if (str->next != NULL)
				dl_lstdelnode(str, stack);
			else
			{
				str->flag = -10;
				return ;
			}
			str = stack->up;
		}
	}
	while (str)
	{
		if (check_quote_not_open(str) == 0)
			return ;
		expend_suite(str, env);
		str = str->next;
	}
	return ;
}
