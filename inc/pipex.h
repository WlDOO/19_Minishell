/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:20:05 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/01 16:44:43 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../pipex/ft_printf/ft_printf.h"

typedef struct s_fd
{
	int		infd;
	int		outfd;
	int		fd[2];
	char	**env;
}			t_fd;

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*path(char **av, char **env, int x);
int		ft_firstpros(char **av, char *env, int y);
char	**ft_check_fullcmd(char **av, int x);
int		ft_second_process(char **av, char *cmd2, t_fd *cmdfd, char **env);
int		ft_first_process(char **av, char *cmd1, t_fd *cmdfd, char **env);
int		ft_start_pipex(char **av, char *cmd1, char *cmd2, t_fd *cmdfd);
void	ft_init(t_fd **cmdfd);
int		ft_error(char *cmd1, char *cmd2, char **av);
void	free_all(char **str);
char	*path2(char **str, char **str2);
char	*ft_strdup(const char *s1);
void	ft_close(t_fd *cmd);
int		ft_end_pipex(char **av, char *cmd2, t_fd *cmdfd);

#endif