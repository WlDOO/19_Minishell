/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:52:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 17:52:50 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_infile_out_file(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 3 || node->flag == 4 || node->flag == 6)
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

void	ft_create_out(char *content)
{
	int	fd;

	fd = 0;
	fd = open(content, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
	{
		g_exit_code = 1;
	}
	close(fd);
}
