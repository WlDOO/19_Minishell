/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:52:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 21:11:30 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_infile_out_file(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 3 || node->flag == 4 || node->flag == 6)
		{
			dl_lstdelnode(node, stack);
			if (node->next != NULL)
			{
				node = node->next;
				dl_lstdelnode(node, stack);
			}
		}
		if (node != NULL)
			node = node->next;
	}
}

void	ft_create_out(char *content)
{
	int	fd;

	fd = 0;
	fd = open(content, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
	{
		g_exit_code = 1;
	}
	close(fd);
}

static int	ft_count_world(t_node *node)
{
	int	i;

	i = 0;
	while (node && node->flag != 1)
	{
		if ((node->flag == 0 || node->flag == 8) && (node->prev == NULL
				|| (node->prev->flag != 3 && node->prev->flag != 4
					&& node->prev->flag != 5 && node->prev->flag != 6 && node)))
			i++;
		node = node->next;
	}
	return (i);
}

char	**ft_add_content(t_node *node, int count, int i)
{
	char	**strs;

	strs = NULL;
	count = ft_count_world(node);
	if (count != 0)
	{
		strs = malloc(sizeof(char *) * (count + 1));
		if (!strs)
			return (NULL);
		while (node != NULL && node->flag != 1 && i <= count)
		{
			if ((node->flag == 0 || node->flag == 8) && (node->prev == NULL
					|| (node->prev->flag != 3 && node->prev->flag != 4
						&& node->prev->flag != 5
						&& node->prev->flag != 6 && node)))
			{
				strs[i] = ft_strdup(node->content);
				i++;
			}
			node = node->next;
		}
		strs[i] = NULL;
	}
	return (strs);
}
