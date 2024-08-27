/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:40:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/27 18:37:15 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_all(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp3;
	char	*tmp;

	tmp = NULL;
	tmp3 = NULL;
	node = stack->up;
	while (node != NULL)
	{
		ft_clear_all_annexe(stack, tmp, tmp3, node);
		if (node != NULL)
			node = node->next;
	}
	ft_clear_all_suite(stack);
}

void	ft_checkcmd(t_stack *stack)
{
	int		count;
	t_node	*node;
	int		i;

	i = 0;
	count = 0;
	node = stack->up;
	// printf_node(stack);
	while (node != NULL)
	{
		count = 0;
		while (node != NULL && node->flag != 1)
		{
			if (node->flag == 8)
				count++;
			node = node->next;
		}
		if (node != NULL && node->flag == 1)
			i++;
		if (count == 0)
			ft_checkflag0(stack, i);
		if (node != NULL)
			node = node->next;
	}
}

void	ft_checkflag0(t_stack *stack, int i)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL && i != 0)
	{
		if (node->flag == 1)
			i--;
		node = node->next;
	}
	while (node != NULL && node->flag != 1)
	{
		if ((node->flag == 0 && node->prev == NULL)
			|| (node->flag == 0 && node->prev->flag != 3
				&& node->prev->flag != 4 && node->prev->flag != 5))
		{
			node->flag = 8;
			break ;
		}
		node = node->next;
	}
}

void	ft_checknode(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		node->flag = 0;
		if (check_sep(node->content[0], "|<>") == 0)
			node = ft_flagcheck(node);
		node = node->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	{
		while (stack->up != NULL)
		{
			temp = stack->up->next;
			free(stack->up);
			stack->up = temp;
		}
		stack->up = NULL;
		stack->low = NULL;
	}
}
