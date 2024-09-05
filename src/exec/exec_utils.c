/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:11:32 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/05 20:45:55 by sadegrae         ###   ########.fr       */
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
		ft_export(env, node, 1);
	else if (ft_strncmp(node->content, "unset", 5) == 0)
		ft_unset(env, node);
	else if (ft_strncmp(node->content, "env", 3) == 0)
		printf_env(env);
	else if (ft_strncmp(node->content, "exit", 4) == 0)
		ft_exit(node->full_cmd, 0);
}

void	ft_perror(void)
{
	exit(1);
}

void	ft_wait(int pid, int status, int count)
{
	while (count != 0)
	{
		if (wait(&status) == pid)
			if (WIFEXITED(status))
				g_exit_code = WEXITSTATUS(status);
		count--;
	}
}

void	ft_putstr_error(char *content)
{
	write(2, "minishell: ", 12);
	ft_putstr_fd(content, 2);
	write(2, ": command not found\n", 21);
}
