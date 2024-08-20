/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:11:32 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/20 14:51:43 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_countcmd(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 8)
			i++;
		node = node->next;
	}
	return (i);
}

void	ft_use_bultin(t_node *node, t_env *env)
{
	if (ft_strncmp(node->content, "echo", 4) == 0)
		ft_echo(node);
	else if (ft_strncmp(node->content, "cd", 2) == 0)
		ft_cd(env, node);
	else if (ft_strncmp(node->content, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(node->content, "export", 6) == 0)
		ft_export(env, node);
	else if (ft_strncmp(node->content, "unset", 5) == 0)
		ft_unset(env, node);
	else if (ft_strncmp(node->content, "env", 3) == 0)
		printf_env(env);
	else if (ft_strncmp(node->content, "exit", 4) == 0)
		ft_exit();
}

