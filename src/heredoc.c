/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:12:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/09 13:22:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	heredoc(t_node *node)
{
	int	fd;
	char	*line;

	fd = open("tmp2", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		line = readline("heredoc> ");
		if (ft_strncmp(line, node->content, 300) == 0)
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
	}
	close (fd);
	return (0);
}