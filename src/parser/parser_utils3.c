/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:06:43 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/27 13:38:45 by najeuneh         ###   ########.fr       */
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
	{
		node->next->out_fd = open(node->next->content, O_RDWR
				| O_CREAT | O_TRUNC, 0644);
		if (node->out_fd == -1)
			printf("zsh: no such file or directory: %s\n", node->next->content);
		return ;
	}
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
			tmp = ft_strjoin(tmp, tmp3->content);
			tmp = ft_strjoin(tmp, " ");
			tmp3 = tmp3->next;
		}
		node->full_cmd = ft_split(tmp, ' ');
		while (node != NULL && node->flag != 1)
			node = node->next;
	}
	else if (node->flag)
		node->full_cmd = ft_split(node->content, ' ');
}
