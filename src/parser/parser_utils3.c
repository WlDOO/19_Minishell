/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:06:43 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/19 17:42:43 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_all_suite(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	if (ft_only_heredoc(stack) != 0)
		return ;
	if (node->flag == 3 && node->prev == NULL && node->next->next == NULL)
		return ;
	if (node->flag == 5 && node->prev == NULL && node->next->next == NULL)
		return ;
	else if (node->flag == 4 && node->prev == NULL && node->next->next == NULL)
		return ;
	while (node != NULL)
	{
		if (node != NULL && node->flag != 8 && node->flag != 1
			&& node->flag != -1)
		{
			dl_lstdelnode(node, stack);
		}
		if (node != NULL)
			node = node->next;
	}
}

void	ft_bultincheck2(t_node *node)
{
	if (ft_strcmp(node->content, "unset") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strcmp(node->content, "env") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strcmp(node->content, "exit") == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
}

void	ft_check_next(t_node **node)
{
	if (*node != NULL)
		*node = (*node)->next;
}

void	ft_look_cmd(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 8)
		{
			if (node->next != NULL && node->next->flag != 1
				&& node->next->flag != 3 && node->next->flag != 4
				&& node->next->flag != 5 && node->next->flag != 6)
			{
				node->next->flag = 0;
				node->next->bultin = 0;
			}
		}
		node = node->next;
	}
}
