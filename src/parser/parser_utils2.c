/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:40:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/19 18:36:00 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_all(t_stack *stack)
{
	t_node	*node;
	char 	*tmp;
	char	*tmp2;
	t_node *tmp3;

	node = stack->up;
	while (node != NULL)
	{
		if (node->next != NULL && node->flag == 8 && node->next->flag == 0)
		{
			tmp2 = ft_strdup(node->content);
			tmp = ft_strjoin(tmp2, " ");
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
		{
			node->full_cmd = ft_split(node->content, ' ');
		}
		if (node != NULL)
			node = node->next;
	}
	node = stack->up;
	if (node->flag == 3 && node->prev == NULL && node->next->next == NULL)
		return ;
	else if (node->flag == 4 && node->prev == NULL && node->next->next == NULL)
	{
		node->next->out_fd = open(node->next->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
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

void	ft_checkcmd(t_stack *stack)
{
	int		count;
	t_node *node;
	int	i = 0;
	count = 0;
	node = stack->up;
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
	t_node *node;

	node = stack->up;
	while (node != NULL && i != 0)
	{
		if (node->flag == 1)
			i--;
		node = node->next;
	}
	while (node != NULL && node->flag != 1)
	{
		if ((node->flag == 0 && node->prev == NULL) || (node->flag == 0 && node->prev->flag != 3 && node->prev->flag != 4))
		{
			node->flag = 8;
			break ;
		}
		node = node->next;	
	}
}
