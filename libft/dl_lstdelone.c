/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:56:26 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/23 15:55:24 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dl_lstdelfront(t_stack *a)
{
	t_node	*temp;

	if (!a)
		return ;
	temp = a->up;
	a->up = a->up->next;
	a->up->prev = NULL;
	free(temp);
}

void	dl_lstdelback(t_stack *a)
{
	t_node	*temp;

	if (!a)
		return ;
	temp = a->low;
	a->low = a->low->prev;
	a->low->next = NULL;
	free(temp);
}

void	dl_lstdelnode(t_node *node, t_stack *stack)
{
	t_node	*tmp;

	tmp = node;
	if (!node)
		return ;
	if (node->prev == NULL)
		dl_lstdelfront(stack);
	else
		node->prev->next = tmp->next;
	if (node->next == NULL)
		dl_lstdelback(stack);
	else
		tmp->next->prev = node->prev;
}
