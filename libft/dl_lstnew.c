/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:18:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/05 19:59:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_node	*dl_lstnew(char *line, int start, int end)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = ft_strcreate(line, start, end);
	node->flag = 0;
	node->bultin = 0;
	node->cmd = NULL;
	node->in = NULL;
	node->out = NULL;
	node->in_fd = 0;
	node->out_fd = 0;
	node->full_cmd = NULL;
	node->heredoc = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
