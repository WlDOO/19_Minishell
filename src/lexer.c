/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:49:55 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/19 19:10:28 by sadegrae         ###   ########.fr       */
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

void	lexer(t_stack *stack, char *line, char **env, int start, t_env *env2)
{
	int		i;
	t_node *node;
	
	node = stack->up;
	i = 0;
	if (!line)
		return;
	while (line[i])
	{
		while (line[i] && (line[i] == 32 || line[i] == '	'))
			i++;
		if (line[i] == '"' || line[i] == 39)
		{
			start = i;
			i++;
			while (line[i] && line[i] != ' ')
			{
				i++;
				if (line[i] == '"' && line[i + 1] == '"')
					i += 2;
			}
			i++;
			dl_lstadd_back(stack, line, start, i);
		}
		else
			i = lexer_suite(stack, line, start, i);
	}
	//(void)env2;
	//printf("%s\n", node->full_cmd[0]);
	// if (execve(node->cmd, node->full_cmd, NULL) == -1)
	// {
	// 	printf("okeyyyy\n");
	// 	return ;
	// }
	ft_expend(stack, env2);
	ft_parser(stack, env, env2);
	exec(stack, env);
}

int	lexer_suite(t_stack *stack, char *line, int start, int i)
{
	if (line[i] && check_sep(line[i], "|&<>()`") == 1)
	{
		start = i;
		while (line[i] && check_sep(line[i], "|&<>()` ") == 1
			&& line[i] != '"')
		{
			i++;
			if (line[i] == '"' && line[i] != 32
				&& check_sep(line[i], "|&<>()`") == 1)
			{
				while (line[i] && line[i] != 34)
				{
					i++;
				}
				i++;
			}
		}
		dl_lstadd_back(stack, line, start, i);
	}
	else if (line[i] && check_sep(line[i], "|&<>()`") == 0)
		i = lexer_suite2(stack, line, start, i);
	else
		i++;
	return (i);
}

int	lexer_suite2(t_stack *stack, char *line, int start, int i)
{
	start = i;
	while (line[i] && check_sep(line[i], "|&<>()`") == 0 && line[i] != '"')
		i++;
	dl_lstadd_back(stack, line, start, i);
	return (i);
}
