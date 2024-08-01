/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:27:31 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/01 15:52:55 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
flag 0 = word
flag 1 = |
flag 2 = &
flag 3 = <
flag 4 = >
flag 5 = (
flag 6 = )
flag 7 = $
*/

t_node	*ft_flagcheck(t_node *node)
{
	if (node->content[0] == '|')
		node->flag = 1;
	else if (node->content[0] == '&')
		node->flag = 2;
	else if (node->content[0] == '<')
		node->flag = 3;
	else if (node->content[0] == '>')
		node->flag = 4;
	else if (node->content[0] == '(')
		node->flag = 5;
	else if (node->content[0] == ')')
		node->flag = 6;
	else if (node->content[0] == '$')
		node->flag = 7;
	else if (node->content[0] == ' ')
		node->flag = -1;
	return (node);
}

void	ft_parser(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->up;
	while (node != NULL)
	{
		node->flag = 0;
		if (check_sep(node->content[0], "|&<>()$`") == 0)
			node = ft_flagcheck(node);
		node = node->next;
		i++;
	}
}

