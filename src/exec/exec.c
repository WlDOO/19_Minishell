/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:58 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/19 18:54:12 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exec(t_stack *stack, t_env *env)
{
	t_node	*node;
	int		count;
	int		pid;
	
	node = stack->up;
	count = ft_countcmd(stack);
	if (count == 1)
	{
		pid = fork();
		if (pid == 0)
			simple_cmd(node, STDOUT_FILENO, STDOUT_FILENO, env);
		
	}
	else if (count > 1)
		multi_cmd(stack, env);
	while (wait(NULL) > 0)
		;
	return (0);
}

int	multi_cmd(t_stack *stack, t_env *env)
{
	t_node	*node;
	int	pipee[2];
	int	prev_fd = -1;
	int pid;
	
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag != 1)
		{
			pipe(pipee);
			pid = fork();
			if (pid == 0)
			{
				close(pipee[0]);
				if (node->prev == NULL)
					simple_cmd(node, STDOUT_FILENO, pipee[1], env);
				else if (node->prev != NULL && node->next != NULL)
					simple_cmd(node, prev_fd, pipee[1], env);
				else if (node->next == NULL)
					simple_cmd(node, prev_fd, STDOUT_FILENO, env);
			}
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

int	simple_cmd(t_node *node,int in_pipe, int out_pipe, t_env *env)
{
	ft_check_fd(node);
	if (node->in_fd != -1)
	{
		if (dup2(node->in_fd, STDIN_FILENO) == -1)
		{
			perror("Error\n");
			exit(1);
		}
		close(node->in_fd);
	}
	else if (dup2(in_pipe, STDIN_FILENO) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	if (node->out_fd != -1)
	{
		if (dup2(node->out_fd, STDOUT_FILENO) == -1)
		{
			perror("Error\n");
			exit(1);
		}
		close(node->out_fd);
	}
	else if (dup2(out_pipe, STDOUT_FILENO) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	// if (node->bultin == 1)
	// 	ft_use_bultin(node, env);
	if (execve(node->cmd, node->full_cmd, list_to_matrix(env)) == -1)
		return (printf("minishell: %s: command not found\n", node->content), 0);
	return (1);
}

void	ft_check_fd(t_node *node)
{
	if (node->in != NULL)
	{
		node->in_fd = open(node->in, O_RDONLY);
		if (node->in_fd == -1)
		{
			printf("zsh: no such file or directory: %s\n", node->in);
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
		}
	}
	else
		node->out_fd = -1;
}

