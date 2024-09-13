/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:36:05 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 21:58:34 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


int	verif_char_special2(char *str, t_node *next)
{
	if (ft_strncmp(str, "<<<", 3) == 0)
		return (printf("minishell: syntax error near unexpected token `<<<'\n"),
			g_exit_code = 1, 0);
	else if (ft_strncmp(str, ">>>>", 4) == 0)
	{
		printf("minishell: syntax error near unexpected token `>>'\n");
		return (g_exit_code = 1, 0);
	}
	else if (ft_strncmp(str, ">>>", 3) == 0)
	{
		printf("minishell: syntax error near unexpected token `>'\n");
		return (g_exit_code = 1, 0);
	}
	else if (ft_strncmp(str, "<", 1) == 0 && next == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (g_exit_code = 1, 0);
	}
	else if (ft_strncmp(str, ">", 1) == 0 && next == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (g_exit_code = 1, 0);
	}
	return (1);
}

void	ft_split_cot(t_node *str)
{
	int	len;
	int	i;
	char	*tmp;

	i = 0;
	len = ft_count_quote(str, 0, 0);
	tmp = malloc(sizeof(char)* len + 1);
	if (!tmp)
		return;
	len = 0;
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
	
	free(str->content);
	str->content = ft_strdup(tmp);
	free(tmp);
}

void convert_dollar(t_node *str, t_env *env)
{
	int	i;
	int	end;
	char *tmp;

	i = 0;
	tmp = NULL;
	while (str->content[i] && str->content[i] != '$')
		i++;
	if (str->content[i] == '$' && (check_sep(str->content[i + 1], "\"' ") == 0 || !str->content[i + 1]))
		return ;
	if (str->content[i] && str->content[i] == '$')
	{
		end = i;
		while (str->content[end] && check_sep(str->content[end], "\"' ") == 1)
			end++;
		tmp = ft_strcreate(str->content, i + 1, end);
	}
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
	while (env)
	{
		if (ft_strcmp(env->attribut, tmp) == 0)
		{
			free(tmp);
			tmp = ft_strjoin(ft_strcpy2(str->content, '$'),ft_strdup(env->content));
			tmp = ft_strjoin(tmp, &str->content[end]);
			free(str->content);
			str->content = ft_strdup(tmp);
			free(tmp);
			return ;
		}
		env = env->next;
	}
	free(tmp);
	tmp = ft_strjoin(ft_strcpy2(str->content, '$'),ft_strdup(""));
	tmp = ft_strjoin(tmp, &str->content[end]);
	free(str->content);
	str->content = ft_strdup(tmp);
	free(tmp);
	return ;
}

void if_or_not_convert(t_node *str, t_env *env)
{
	int	i;

	i = 0;
	while(str->content[i])
	{
		if (str->content[i] == '"')
		{
			i++;
			while (str->content[i] && str->content[i] != '"')
			{
				if (str->content[i] == '$')
				{
					convert_dollar(str, env);
				}
				i++;
			}
			i++;
		}
		else if (str->content[i] == 39)
		{
			i++;
			while (str->content[i] && str->content[i] != 39)
			{
				if (str->content[i] == '$')
					return ;
				i++;
			}
			i++;
		}
		else
		{
			if (str->content[i] == '$')
			{
				convert_dollar(str, env);
				return ;
			}
			i++;
		}
	}
	
}

int check_if_dollard(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}