/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:44:44 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/09 15:59:58 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_check_out(t_node *node)
{
	if (node->out != NULL)
	{
		if (node->append == 1)
			node->out_fd = open(node->out, O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			node->out_fd = open(node->out, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (node->out_fd == -1)
		{
			printf("zsh: no such file or directory: %s\n", node->out);
			g_exit_code = 1;
			exit(g_exit_code);
		}
	}
	else
		node->out_fd = -1;
}
