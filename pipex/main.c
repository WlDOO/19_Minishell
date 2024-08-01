/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:13:10 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/01 16:31:34 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **env)
{
	char	*cmd1;
	char	*cmd2;
	t_fd	*cmdfd;

	if (ac != 5)
		return (ft_printf("infile command1 command2 outfile\n"), 1);
	ft_init(&cmdfd);
	cmdfd->env = env;
	cmd1 = path(av, env, 2);
	cmd2 = path(av, env, 3);
	if (!cmd2)
		return (ft_error(cmd1, cmd2, av), free (cmdfd), 1);
	cmdfd->infd = open(av[1], O_RDONLY);
	if (cmdfd->infd == -1)
		return (ft_printf("zsh: no such file or directory: %s\n", av[1]),
			free (cmdfd), free(cmd1), free(cmd2), 1);
	cmdfd->outfd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmdfd->outfd == -1)
		return (ft_printf("zsh: no such file or directory: %s\n", av[4]),
			free (cmdfd), free(cmd1), free(cmd2), 1);
	if (ft_start_pipex(av, cmd1, cmd2, cmdfd) == 0)
		return (ft_close(cmdfd), free (cmdfd), free(cmd1), free(cmd2), 1);
	return (ft_close(cmdfd), free (cmdfd), free(cmd1), free(cmd2), 0);
}

int	ft_start_pipex(char **av, char *cmd1, char *cmd2, t_fd *cmdfd)
{
	pid_t		id;

	id = 0;
	if (pipe(cmdfd->fd) == -1)
		return (write(2, "Error\n", 6), 0);
	id = fork();
	if (id == -1)
	{
		write(2, "Error fail fork\n", 17);
		exit(1);
	}
	if (id == 0)
	{
		if (ft_first_process(av, cmd1, cmdfd, cmdfd->env) == 0)
			return (0);
	}
	if (ft_end_pipex(av, cmd2, cmdfd) == 0)
		return (0);
	while (wait(NULL) > 0)
		;
	return (1);
}

int	ft_end_pipex(char **av, char *cmd2, t_fd *cmdfd)
{
	pid_t		id2;

	id2 = 0;
	id2 = fork();
	if (id2 == -1)
	{
		write(2, "Error fail fork\n", 17);
		exit(1);
	}
	if (id2 == 0)
		if (ft_second_process(av, cmd2, cmdfd, cmdfd->env) == 0)
			return (0);
	ft_close(cmdfd);
	return (1);
}

void	ft_init(t_fd **cmdfd)
{
	(*cmdfd) = malloc(sizeof(t_fd));
	(*cmdfd)->infd = 0;
	(*cmdfd)->outfd = 0;
}

int	ft_error(char *cmd1, char *cmd2, char **av)
{
	if (!cmd1)
	{
		ft_printf("zsh: command not found: %s\n", av[2]);
		if (!cmd2)
			return (ft_printf("zsh: command not found: %s\n", av[3]), 0);
		free (cmd2);
		return (0);
	}
	else if (!cmd2)
	{
		free (cmd1);
		return (ft_printf("zsh: command not found: %s\n", av[3]), 0);
	}
	return (1);
}
