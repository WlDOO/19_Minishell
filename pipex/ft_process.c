/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:00:05 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/18 14:44:05 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_first_process(char **av, char *cmd1, t_fd *cmdfd, char **env)
{
	char	**str;

	close (cmdfd->fd[0]);
	(void)env;
	if (dup2(cmdfd->infd, STDIN_FILENO) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	if (dup2(cmdfd->fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	close (cmdfd->fd[1]);
	str = ft_check_fullcmd(av, 2);
	if (execve(cmd1, str, NULL) == -1)
		return (free_all(str), 0);
	return (1);
}

int	ft_second_process(char **av, char *cmd2, t_fd *cmdfd, char **env)
{
	char	**str;

	close (cmdfd->fd[1]);
	(void)env;
	if (dup2(cmdfd->fd[0], STDIN_FILENO) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	close (cmdfd->fd[0]);
	if (dup2(cmdfd->outfd, STDOUT_FILENO) == -1)
	{
		perror("Error\n");
		exit(1);
	}
	str = ft_check_fullcmd(av, 3);
	if (execve(cmd2, str, NULL) == -1)
		return (free_all(str), 0);
	return (1);
}

char	**ft_check_fullcmd(char **av, int x)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = ft_split(av[x], ' ');
	if (str == NULL)
		return (NULL);
	return (str);
}
