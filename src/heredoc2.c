/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:51:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/05 20:04:28 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_node_in(t_stack *stack, int pipe, char *infile, int i)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL && pipe > 0)
	{
		node = node->next;
		if (node->flag == 1)
			pipe--;
	}
	while (node != NULL)
	{
		if (node->flag == 8)
		{
			node->in = ft_strdup(infile);
			node->heredoc = i;
			return ;
		}
		node = node->next;
	}
}

void	delete_heredoc(t_stack *stack, int count)
{
	char	*infile;
	t_node	*node;
	char	*count_nbr;

	node = stack->up;
	infile = ft_strdup("");
	if (ft_countcmd(stack) == 0)
		return ;
	while (node != NULL)
	{
		count = node->heredoc;
		node = node->next;
	}
	while (count > 0)
	{
		free(infile);
		count--;
		infile = ft_strdup("/tmp/.tmp");
		count_nbr = ft_itoa(count);
		infile = ft_strjoin(infile, count_nbr);
		free (count_nbr);
		unlink(infile);
	}
	free (infile);
}

void	ft_check_full_path(t_node *node)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (node->content[0] == '.')
		return ;
	if (ft_strcmp(node->content, node->cmd) == 0)
	{
		free (node->content);
		while (node->cmd[i])
		{
			if (node->cmd[i] == '/')
				y = i;
			i++;
		}
		node->content = ft_strcreate(node->cmd, y + 1, i);
	}
}
