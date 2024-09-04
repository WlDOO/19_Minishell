/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:18:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/04 16:25:03 by najeuneh         ###   ########.fr       */
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
	node->cmd = NULL;
	node->full_cmd = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
