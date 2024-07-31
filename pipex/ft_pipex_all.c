/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:20:47 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/29 19:06:22 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_check(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PATH", 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*path(char **av, char **env, int x)
{
	int		i;
	int		j;
	char	**str;
	char	**str2;
	char	*cmp;

	j = -1;
	str = NULL;
	str2 = ft_split(av[x], ' ');
	if (str2 == NULL)
		return (NULL);
	if (access(str2[0], F_OK | X_OK) == 0)
	{
		cmp = ft_strdup(str2[0]);
		return (free_all(str2), cmp);
	}
	i = ft_check(env);
	if (i == -1)
		return (0);
	str = ft_split(env[i] + 5, ':');
	if (str == NULL)
		return (NULL);
	cmp = path2(str, str2);
	return (cmp);
}

char	*path2(char **str, char **str2)
{
	int		j;
	char	*cmp;

	j = -1;
	while (str[++j] != NULL)
	{
		str[j] = ft_strjoin(str[j], "/");
		str[j] = ft_strjoin(str[j], str2[0]);
		if (access(str[j], F_OK | X_OK) == 0)
		{
			cmp = ft_strdup(str[j]);
			free_all(str);
			return (free_all(str2), cmp);
		}
	}
	return (free_all(str), free_all(str2), NULL);
}

void	ft_close(t_fd *cmdfd)
{
	close(cmdfd->infd);
	close(cmdfd->outfd);
	close (cmdfd->fd[0]);
	close (cmdfd->fd[1]);
}
