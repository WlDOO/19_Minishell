/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:49:55 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/13 15:02:37 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

void	lexer(t_stack *stack, char *line, int start, t_env *envp)
{
	int		i;
	t_node	*node;

	node = NULL;
	i = 0;
	while (line && line[i])
	{
		while (line[i] && (line[i] == 32 || line[i] == '	'))
			i++;
		if (line[i] && check_sep(line[i], "<>|\"' ") == 1)
		{
			start = i;
			i = ft_lexer_normal(line, start, i);
			dl_lstadd_back(stack, line, start, i);
		}
		if (check_sep(line[i], "<>|\"'") == 0)
		{
			start = i;
			i += ft_lexer_expextion2(line, start, i);
			i++;
			dl_lstadd_back(stack, line, start, i);
		}
	}
	ft_lexer2(line, stack, node, envp);
}

int	ft_lexer_expextion2(char *line, int start, int i)
{
	start = i;
	if (line[i] == 39)
	{
		i++;
		while (line[i] && line[i] != 39)
			i++;
		if (line[i + 1] == 34)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 34)
				i++;
		}
		else if (line[i + 1] == 39)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 39)
				i++;
		}
		if (line[i + 1] != ' ')
			while (line[i + 1] && check_sep(line[i + 1], "<>| ") == 1)
				i++;
	}
	i = ft_lexer_expextion2_2(line, i, start);
	return (i - start);
}

int	ft_lexer_expextion(char *line, int start, int i)
{
	start = i;
	if (line[i] == 39)
	{
		i++;
		while (line[i] && line[i] != 39)
			i++;
		if (line[i + 1] == 34)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 34)
				i++;
		}
		else if (line[i + 1] == 39)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 39)
				i++;
		}
		if (line[i + 1] != ' ')
			while (line[i + 1] && check_sep(line[i + 1], "<>| ") == 1)
				i++;
	}
	i = ft_lexer_expextion_2(line, i);
	return (i - start);
}

void	ft_lexer2(char *line, t_stack *stack, t_node *node, t_env *envp)
{
	if (!line || stack->up == NULL)
		return ;
	if (ft_strcmp(stack->low->content, "|") == 0)
	{
		printf("minishell: syntax error: unexpected end of file\n");
		return ;
	}
	node = stack->up;
	if (ft_lexer_verif(node) == 1)
		return ;
	ft_expend(stack, envp);
	if (g_exit_code == -1 || stack->up->flag == -10)
	{
		if (stack->up->flag == -10)
		{
			g_exit_code = 0;
			return ;
		}
		g_exit_code = 1;
		printf("minishell: syntax error: unexpected end of file\n");
		return ;
	}
	ft_parser(stack, envp);
	exec(stack, envp, 0);
}
