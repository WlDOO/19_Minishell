/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:58 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/27 18:54:29 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exec(t_stack *stack, t_env *env)
{
	t_node	*node;
	int		count;
	int		pid;

	node = stack->up;
	printf("coucou");
	printf_node(stack);
	count = ft_countcmd(stack);
	if (count == 1)
	{
		pid = fork();
		if (node->bultin == 1)
		{
			if (pid == 0)
			{
				g_exit_code = 1;
				exit(1);
			}
			else
			{
				ft_use_bultin(node, env);
			}
		}
		else if (pid == 0)
		{
			g_exit_code = simple_cmd(node, STDOUT_FILENO, STDOUT_FILENO, env);
			exit(g_exit_code);
		}
	}
	else if (count > 1)
		multi_cmd(stack, env);
	while (wait(NULL) > 0)
		;
	return (delete_heredoc(stack, 0), 0);
}

int	multi_cmd(t_stack *stack, t_env *env)
{
	t_node	*node;
	int		pipee[2];
	int		prev_fd;
	int		pid;

	prev_fd = -1;
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag != 1)
		{
			pipe(pipee);
			pid = fork();
			if (pid == 0)
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
	return (0);
}

int	multi_cmd2(t_node *node, int pipe[2], int prev_fd, t_env *env)
{
	close(pipe[0]);
	if (node->prev == NULL)
		g_exit_code = simple_cmd(node, STDOUT_FILENO, pipe[1], env);
	else if (node->prev != NULL && node->next != NULL)
	{
		g_exit_code = simple_cmd(node, prev_fd, pipe[1], env);
	}
	else if (node->next == NULL)
		g_exit_code = simple_cmd(node, prev_fd, STDOUT_FILENO, env);
	return (0);
}

int	simple_cmd(t_node *node, int in_pipe, int out_pipe, t_env *env)
{
	ft_check_fd(node);
	printf("out %s\n", node->out);
	if (node->in_fd != -1)
	{
		if (dup2(node->in_fd, STDIN_FILENO) == -1)
			ft_perror();
		close(node->in_fd);
	}
	else if (dup2(in_pipe, STDIN_FILENO) == -1)
		ft_perror();
	if (node->out_fd != -1)
	{
		printf("coucou");
		if (dup2(node->out_fd, STDOUT_FILENO) == -1)
			ft_perror();
		close(node->out_fd);
	}
	else if (dup2(out_pipe, STDOUT_FILENO) == -1)
		ft_perror();
	if (node->bultin == 1)
		ft_use_bultin(node, env);
	else if (execve(node->cmd, node->full_cmd, list_to_matrix(env)) == -1)
	{
		printf("minishell: %s: command not found\n", node->content);
		exit(127);
	}
	return (0);
}

void	ft_check_fd(t_node *node)
{
	if (node->in != NULL)
	{
		node->in_fd = open(node->in, O_RDONLY);
		if (node->in_fd == -1)
		{
			printf("zsh: no such file or directory: %s\n", node->in);
			g_exit_code = 1;
			return ;
		}
	}
	else
		node->in_fd = -1;
	if (node->out != NULL)
	{
		node->out_fd = open(node->out, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (node->out_fd == -1)
		{
			printf("zsh: no such file or directory: %s\n", node->out);
			g_exit_code = 1;
			return ;
		}
	}
	else
		node->out_fd = -1;
}
