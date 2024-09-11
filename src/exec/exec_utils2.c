/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:44:44 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/11 20:08:21 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	is_directory(char *cmd)
{
	struct stat data;

	if (stat(cmd, &data) == -1)
	{
		perror("stat");
		exit(1);
	}
	if ((data.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd , 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
}
void	not_fount(char *cmd)
{
	write(2, "minishell: ", 12);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": commad not found\n", 2);
	exit (127);
}


void	error_manage(char *cmd)
{
	if(ft_strncmp(cmd, "./",2) == 0)
	{
		if (errno == EACCES)
			is_directory(ft_strchr(cmd, '/') + 1);
		else
			exit(1);
	}
	not_fount(cmd);
}
void	parent_bultins(t_node *node, t_env *env)
{
	ft_use_bultin(node, env);
	while (wait(NULL) > 0)
		;
}

