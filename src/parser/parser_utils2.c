/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:40:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/14 13:33:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_all(t_stack *stack)
{
	t_node	*node;
	char *tmp;
	char	*tmp2;

	node = stack->up;
	while (node != NULL)
	{
		if (node->next != NULL && node->flag == 8 && node->next->flag == 0)
		{
			tmp2 = ft_strdup(node->content);
			tmp = ft_strjoin(tmp2, " ");
			if (node->next->content != NULL)
				tmp = ft_strjoin(tmp, node->next->content);
			node->full_cmd = ft_split(tmp, ' ');
		}
		else if (node->flag == 8 && node->next == NULL)
			node->full_cmd = ft_split(node->content, ' ');
		node = node->next;
	}
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag != 8 && node->flag != 1)
			dl_lstdelnode(node, stack);
		node = node->next;
	}
}
