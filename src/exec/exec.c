/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:58 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 17:12:22 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exec(t_stack *stack, t_env *env, int status)
{
	t_node	*node;
	int		count;
	int		pid;

	node = stack->up;
	count = ft_countcmd(stack);
	pid = 0;
	ft_control(1);
	if (count == 1)
	{
		pid = fork();
		while (node && node->flag != 8)
			node = node->next;
		if (node->bultin == 1 && node->out == NULL)
		{
			if (pid == 0)
				exit(g_exit_code);
			return (parent_bultins(node, env), 0);
		}
		else if (pid == 0)
			simple_cmd(node, STDOUT_FILENO, STDOUT_FILENO, env);
	}
	else if (count > 1)
		multi_cmd(stack, env, &pid);
	return (ft_wait(pid, status, count), delete_heredoc(stack, 0), 0);
}

int	multi_cmd(t_stack *stack, t_env *env, int *pid)
{
	t_node	*node;
	int		pipee[2];
	int		prev_fd;

	prev_fd = -1;
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag != 1 && node->flag == 8)
		{
			pipe(pipee);
			*pid = fork();
			if (*pid == 0)
				multi_cmd2(node, pipee, prev_fd, env);
			else
			{
				close(prev_fd);
				prev_fd = pipee[0];
				close(pipee[1]);
			}
		}
		node = node->next;
	}
	return (g_exit_code);
}

int	multi_cmd2(t_node *node, int pipe[2], int prev_fd, t_env *env)
{
	close(pipe[0]);
	if (node->prev == NULL)
		simple_cmd(node, STDOUT_FILENO, pipe[1], env);
	else if (node->prev != NULL && node->next != NULL)
		simple_cmd(node, prev_fd, pipe[1], env);
	else if (node->next == NULL)
		simple_cmd(node, prev_fd, STDOUT_FILENO, env);
	return (g_exit_code);
}

void	simple_cmd(t_node *node, int in_pipe, int out_pipe, t_env *env)
{
	ft_check_fd(node);
	if (node->in_fd != -1 && node->full_cmd[1] == NULL)
	{
		if (dup2(node->in_fd, STDIN_FILENO) == -1)
			ft_perror();
		close(node->in_fd);
	}
	else if (dup2(in_pipe, STDIN_FILENO) == -1)
		ft_perror();
	if (node->out_fd != -1)
	{
		if (dup2(node->out_fd, STDOUT_FILENO) == -1)
			ft_perror();
		close(node->out_fd);
	}
	else if (dup2(out_pipe, STDOUT_FILENO) == -1)
		ft_perror();
	if (node->bultin == 1)
	{
		ft_use_bultin(node, env);
		exit(g_exit_code);
	}
	execve(node->cmd, node->full_cmd, list_to_matrix(env));
	error_manage(node->content);
}

void	ft_check_fd(t_node *node)
{
	node->in_fd = -1;
	node->out_fd = -1;
	if (node->in != NULL)
	{
		node->in_fd = open(node->in, O_RDONLY);
		if (node->in_fd == -1)
		{
			write(2, "minishell: ", 12);
			write(2, node->in, ft_strlen(node->in));
			write(2, "no such file or directory: ", 33);
			write(2, "\n", 2);
			g_exit_code = 1;
			exit(g_exit_code);
		}
	}
	else
		node->in_fd = -1;
	ft_check_out(node);
}
