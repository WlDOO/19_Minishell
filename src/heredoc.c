/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:12:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/04 18:16:28 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	heredoc(t_stack *stack)
{
	int		i;
	t_node	*node;

	node = stack->up;
	i = ft_count_heredoc(stack);
	if (i == 0)
		return ;
	multi_heredoc(stack, NULL, -1, 0);
	return ;
}

void	multi_heredoc(t_stack *stack, char *infile, int i, int pipe)
{
	t_node	*node;
	char	*count_nbr;

	node = stack->up;
	while (node != NULL)
	{
		while (node != NULL && node->flag != 1)
		{
			if (node->flag == 5)
			{
				free(infile);
				count_nbr = ft_itoa(++i);
				infile = ft_strjoin(ft_strdup("tmp"), count_nbr);
				create_here_doc(node->next->content, infile);
				free (count_nbr);
			}
			node = node->next;
		}
		ft_node_in(stack, pipe, infile, i + 1);
		if (node != NULL)
			node = node->next;
		pipe++;
	}
	multi_heredoc2(stack, infile, i + 1);
	free (infile);
}

void	multi_heredoc2(t_stack *stack, char *infile, int i)
{
	if (ft_countcmd(stack) == 0)
	{
		while (i > 0)
		{
			free(infile);
			i--;
			infile = ft_strdup("tmp");
			infile = ft_strjoin(infile, ft_itoa(i));
			printf("%s\n", infile);
			unlink(infile);
		}
	}
}

int	ft_count_heredoc(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 5)
			i++;
		node = node->next;
	}
	return (i);
}

void	create_here_doc(char *str, char *infile)
{
	int		fd;
	char	*line;

	fd = open(infile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_control(0);
	while (1)
	{
		line = readline("heredoc> ");
		if (line == NULL)
			break ;
		else if (ft_strcmp(line, str) == 0)
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
	}
	close (fd);
}
