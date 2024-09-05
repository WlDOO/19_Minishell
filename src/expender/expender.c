/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 16:59:28 by sadegrae         ###   ########.fr       */
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


int count_char(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char *copy_without_char(char *str, char c)
{
	int	i;
	char *tmp;
	int	j;

	j = 0;
	i = 0;
	tmp = malloc(sizeof(char) * ((ft_strlen(str) - count_char(str, c)) + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

void	expend_verif(t_env *env, int count, t_node *str, char *first_sep)
{
	if (count == -2)
		return ;
	if (count == -1)
	{
		if (check_char(str->content, '"') == 1 || check_char(str->content, '\'') == 1)
		{
			if (check_char(str->content, '"') == 1)
			{
				str->content = copy_without_char(str->content, '"');
			}
			else
				str->content = copy_without_char(str->content, '\'');
		}
		if (check_char(str->content, '=') == 1)
			return ;
		printf("minishell: syntax error: unexpected end of file\n");
		g_exit_code = -1;
		return ;
	}
	if (count != 0)
		expend_if_dollard(env, str, first_sep, count);
	else
		expend_ifnot_dollard(env, str);
}

void ft_expender_suite(t_node *str, t_env *env)
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
	int		count;
	char	*first_sep;
	t_node	*str;

	if (stack->up->next == NULL)
		return ;
	str = stack->up;
	str = str->next;
	if (verif_char_special(str->content, str->next) == 0)
	{
		ft_expender_suite(str, env);
		return ;
	}
	count = count_guillmet(str->content, 0, 0);
	first_sep = check_first_sep(str->content);
	expend_verif(env, count, str, first_sep);
	free(first_sep);
	g_exit_code = 0;
	return ;
}
