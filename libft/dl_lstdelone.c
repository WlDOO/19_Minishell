/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:56:26 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/04 16:34:06 by najeuneh         ###   ########.fr       */
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
	free(temp->content);
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
	free(temp->content);
	if (temp->full_cmd != NULL)
		ft_free_all(temp->full_cmd);
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
	else if (node->next == NULL)
		dl_lstdelback(stack);
	else
	{
		node->prev->next = tmp->next;
		free (node->content);
		ft_free_all(node->full_cmd);
		free (node);
		tmp->next->prev = node->prev;
	}
}
