/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:36:05 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/10 19:33:57 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


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
	printf("pitier = %s\n", str->content);
}

