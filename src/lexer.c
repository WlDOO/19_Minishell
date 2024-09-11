/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:49:55 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/11 21:16:29 by sadegrae         ###   ########.fr       */
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
			while (line[i] && check_sep(line[i], "<>| ") == 1)
				i++;
			dl_lstadd_back(stack, line, start, i);
		}
		if (check_sep(line[i], "<>|\"'") == 0)
		{
			start = i;
			i = ft_lexer_expextion(line, start, i);
			i++;
			dl_lstadd_back(stack, line, start, i);
		}

	}
	ft_lexer2(line, stack, node, envp);
}

int	ft_lexer_expextion(char *line, int start, int i)
{
	start = i;
	if (line[i] == 39)
	{
		i++;
		while (line[i] && line[i] != 39)
		{
			i++;
		}
		if (line[i + 1] != ' ')
			while(line[i + 1] && check_sep(line[i + 1], "<>| ") == 1)
				i++;
	}
	if (line[i] == 34)
	{
		i++;
		while (line[i] && line[i] != 34)
			i++;
		if (line[i + 1] == 34)
		{
			i++;
			while (line[i + 1] && line[i + 1] != 34)
				i++;
		}
		if (line[i + 1] != ' ')
			while(line[i + 1] && check_sep(line[i + 1], "<>| ") == 1)
				i++;
	}
	else
	{
		while (line[i] && line[start] == line[i + 1])
			i++;
	}
	return(i);
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
	while (node != NULL)
	{
		if (verif_char_special2(node->content, node->next) == 0)
			return ;
		node = node->next;
	}
	ft_print(stack);
	ft_expend(stack, envp);
	if (g_exit_code == -1)
	{
		g_exit_code = 1;
		printf("minishell: syntax error: unexpected end of file\n");
		return ;
	}
	ft_parser(stack, envp);
	exec(stack, envp, 0);
	
}
