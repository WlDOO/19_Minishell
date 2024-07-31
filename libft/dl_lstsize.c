/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:38:46 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/03 20:09:31 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	dl_lstsize(t_stack *stack)
{
	int		i;
	t_node	*node;

	node = stack->up;
	i = 0;
	if (!stack)
		return (0);
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

	// ft_printf("-----------a-----------\n");
	// while (stack->up != NULL)
	// {
	// 	printf("%lld\n", stack->up->nbr);
	// 	stack->up = stack->up->next;
	// }