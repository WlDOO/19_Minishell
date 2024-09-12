/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 20:49:26 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_count_quote(t_node *str, int i, int len)
{
	while (str->content[i])
	{
		if (str->content[i] == '"')
		{
			i++;
			while (str->content[i] && str->content[i++] != '"')
				len++;
			i++;
		}
		else if (str->content[i] == 39)
		{
			i++;
			while (str->content[i] && str->content[i++] != 39)
				len++;
			i++;
		}
		else
		{
			i++;
			len++;
		}
	}
	return(len);
}

int	verif_char_special(char *str, t_node *next)
{
	int	i;

	i = 0;
	(void)next;
	while (str[i])
		i++;
	if (str[i - 1] == '/')
		return (0);
	if (ft_strncmp(str, "..", 2) == 0)
		return (0);
	if (ft_strcmp(str, ".") == 0)
		return (0);
	if (ft_strcmp(str, "~") == 0)
		return (0);
	if (ft_strcmp(str, "_") == 0)
		return (0);
	return (1);
}

int check_quote_not_open(t_node *str)
{
	int	i;

	i = 0;
	while (str->content[i])
	{
		if (str->content[i] == '"')
		{
			i++;
			if (!str->content[i])
			{
				g_exit_code = 1;
				return (0);
			}
			while (str->content[i] && str->content[i] != '"')
			{
				i++;
				if (!str->content[i])
				{
					g_exit_code = 1;
					return (0);
				}
			}
			i++;
		}
		else if (str->content[i] == 39)
		{
			i++;
			if (!str->content[i])
			{
				g_exit_code = 1;
				return (0);
			}
			while (str->content[i] && str->content[i] != 39)
			{
				i++;
				if (!str->content[i])
				{
					g_exit_code = 1;
					return (0);
				}
			}
			i++;
		}
		else
		{
			i++;
		}
	}
	return(1);
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

void	ft_expend(t_stack *stack, t_env *env)
{
	t_node	*str;

	str = stack->up;
	if (str->content[0] == '$')
	{
		
		if (empty_dollard_first_place(env, str->content) == 0)
		{
			if (str->next != NULL)
			{
				dl_lstdelnode(str, stack);
				str = stack->up;
			}
			else
			{
				str->flag = -10;
				return ;
			}
		}
	}
	while (str)
	{
		if (check_quote_not_open(str) == 0)
			return ;
		if (check_if_dollard(str->content) == 1)
			if_or_not_convert(str, env);
		ft_split_cot(str);
		str = str->next;
	}
	return ;
}
