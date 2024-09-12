/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:30:44 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 22:32:13 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_if_dollard(char *str)
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

int	verif_char_special2(char *str, t_node *next)
{
	if (ft_strncmp(str, "<<<", 3) == 0)
		return (printf("minishell: syntax error near unexpected token `<<<'\n"),
			g_exit_code = 1, 0);
	if (ft_strncmp(str, ">>>>", 4) == 0)
	{
		printf("minishell: syntax error near unexpected token `>>'\n");
		return (g_exit_code = 1, 0);
	}
	if (ft_strncmp(str, ">>>", 3) == 0)
	{
		printf("minishell: syntax error near unexpected token `>'\n");
		return (g_exit_code = 1, 0);
	}
	if (ft_strncmp(str, "<", 1) == 0 && next == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (g_exit_code = 1, 0);
	}
	if (ft_strncmp(str, ">", 1) == 0 && next == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (g_exit_code = 1, 0);
	}
	return (1);
}

void	if_or_not_convert(t_node *str, t_env *env, int i)
{
	while (str->content[i++])
	{
		if (str->content[i - 1] == '"')
		{
			while (str->content[i] && str->content[i] != '"')
				if (str->content[i++] == '$')
					convert_dollar(str, env);
			i++;
		}
		else if (str->content[i - 1] == 39)
		{
			while (str->content[i] && str->content[i] != 39)
				if (str->content[i++] == '$')
					return ;
			i++;
		}
		else
		{
			if (str->content[i - 1] == '$')
			{
				convert_dollar(str, env);
				return ;
			}
		}
	}
}

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
	return (len);
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
