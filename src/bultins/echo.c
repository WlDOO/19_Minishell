/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:11:06 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:27 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_echo(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	node = node->next;
	if (node != NULL)
		printf("%s", node->content);
	printf("\n");
}
