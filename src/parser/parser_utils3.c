/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:06:43 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/30 14:13:55 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_all_suite(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	if (node->flag == 3 && node->prev == NULL && node->next->next == NULL)
		return ;
	if (node->flag == 5 && node->prev == NULL && node->next->next == NULL)
		return ;
	else if (node->flag == 4 && node->prev == NULL && node->next->next == NULL)
		return ;
	while (node != NULL)
	{
		if (node != NULL && node->flag != 8 && node->flag != 1)
			dl_lstdelnode(node, stack);
		if (node != NULL)
			node = node->next;
	}
}

void	ft_clear_all_annexe(t_stack *stack, char *tmp,
		t_node *tmp3, t_node *node)
{
	if (ft_count_heredoc(stack) != 0 && ft_countcmd(stack) == 0)
		return ;
	if (node->next != NULL && node->flag == 8 && node->next->flag == 0)
	{
		tmp = ft_strdup(node->content);
		tmp = ft_strjoin(tmp, " ");
		tmp3 = node->next;
		while (tmp3 != NULL && tmp3->flag != 1)
		{
			printf("tmp = %s %d\n", node->next->content, node->next->flag);
			tmp = ft_strjoin(tmp, tmp3->content);
			tmp = ft_strjoin(tmp, " ");
			tmp3 = tmp3->next;
		}
		node->full_cmd = ft_split(tmp, ' ');
		while (node != NULL && node->flag != 1)
			node = node->next;
	}
	else if (node->flag != 3 && node->flag != 4 && node->flag != 1)
		node->full_cmd = ft_split(node->content, ' ');
}

void	ft_bultincheck2(t_node *node)
{
	if (ft_strncmp(node->content, "unset", 5) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "env", 3) == 0)
	{
		node->flag = 8;
		node->bultin = 1;
	}
	else if (ft_strncmp(node->content, "exit", 4) == 0)
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
				&& node->next->flag != 5)
			{
				printf("%s %d\n", node->next->content, node->next->flag);
				node->next->flag = 0;
				node->next->bultin = 0;
			}
		}
		node = node->next;
	}
}
