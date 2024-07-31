/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:27:35 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/30 17:04:10 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dl_lstadd_front(t_stack *a, char *line, int start, int end)
{
	t_node	*new;

	new = dl_lstnew(line, start, end);
	if (a->up == NULL)
	{
		a->up = new;
		a->low = new;
	}
	else
	{
		new->next = a->up;
		a->up->prev = new;
		a->up = new;
	}
}
