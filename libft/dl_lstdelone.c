/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:56:26 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/04 18:21:28 by najeuneh         ###   ########.fr       */
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
