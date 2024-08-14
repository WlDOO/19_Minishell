/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:18:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/13 17:44:25 by najeuneh         ###   ########.fr       */
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
	node->full_cmd = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
