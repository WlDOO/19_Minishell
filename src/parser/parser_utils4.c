/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:52:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 17:02:19 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_infile_out_file(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 3 || node->flag == 4 || node->flag == 5 || node->flag == 6)
		{
			dl_lstdelnode(node, stack);
			if (node->next != NULL)
			{
				node = node->next;
				dl_lstdelnode(node, stack);
			}
		}
		if (node != NULL)
			node = node->next;
	}
}
