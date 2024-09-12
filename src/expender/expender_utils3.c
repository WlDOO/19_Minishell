/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:36:05 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 22:33:00 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_copy_cot(t_node *str, char *tmp, int len, int i)
{
	while (str->content[i])
	{
		if (str->content[i] == '"')
		{
			i++;
			while (str->content[i] && str->content[i] != '"')
				tmp[len++] = str->content[i++];
			i++;
		}
		else if (str->content[i] == 39)
		{
			i++;
			while (str->content[i] && str->content[i] != 39)
				tmp[len++] = str->content[i++];
			i++;
		}
		else
			tmp[len++] = str->content[i++];
	}
	tmp[len] = '\0';
	return (tmp);
}

void	ft_split_cot(t_node *str)
{
	int		len;
	char	*tmp;

	len = ft_count_quote(str, 0, 0);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return ;
	tmp = ft_copy_cot(str, tmp, 0, 0);
	free(str->content);
	str->content = ft_strdup(tmp);
	free(tmp);
}

void	convert_dollar_suite2(t_node *str, t_env *env, int end, char *tmp)
{
	while (env)
	{
		if (ft_strcmp(env->attribut, tmp) == 0)
		{
			free(tmp);
			tmp = ft_strjoin(ft_strcpy2(str->content, '$'),
					ft_strdup(env->content));
			tmp = ft_strjoin(tmp, &str->content[end]);
			free(str->content);
			str->content = ft_strdup(tmp);
			free(tmp);
			return ;
		}
		env = env->next;
	}
	free(tmp);
	tmp = ft_strjoin(ft_strcpy2(str->content, '$'), ft_strdup(""));
	tmp = ft_strjoin(tmp, &str->content[end]);
	free(str->content);
	str->content = ft_strdup(tmp);
	free(tmp);
	return ;
}

void	convert_dollar_suite(t_node *str, t_env *env, int end, char *tmp)
{
	int	i;

	i = 0;
	if (tmp[0] == '?')
	{
		tmp = ft_strjoin(ft_itoa(g_exit_code), &tmp[1]);
		tmp = ft_strjoin(ft_strcpy2(str->content, '$'), tmp);
		tmp = ft_strjoin(tmp, &str->content[end]);
		free(str->content);
		str->content = ft_strdup(tmp);
		free(tmp);
		return ;
	}
	convert_dollar_suite2(str, env, end, tmp);
}

void	convert_dollar(t_node *str, t_env *env)
{
	int		i;
	int		end;
	char	*tmp;

	i = 0;
	tmp = NULL;
	end = 0;
	while (str->content[i] && str->content[i] != '$')
		i++;
	if (str->content[i] == '$' && (check_sep(str->content[i + 1], "\"' ") == 0
			|| !str->content[i + 1]))
		return ;
	if (str->content[i] && str->content[i] == '$')
	{
		end = i;
		while (str->content[end] && check_sep(str->content[end], "\"' ") == 1)
			end++;
		tmp = ft_strcreate(str->content, i + 1, end);
	}
	convert_dollar_suite(str, env, end, tmp);
}
