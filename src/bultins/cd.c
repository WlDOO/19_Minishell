/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:08 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/03 15:13:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*malloc_dst(int len)
{
	char	*dst;

	dst = malloc(sizeof(char) * (len + 2));
	if (!dst)
		return (NULL);
	return (dst);
}

int	ft_strrcmp(char *st1, char *st2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st1[i])
		i++;
	while (st2[j])
		j++;
	j--;
	i--;
	if (st2[j] == '/')
		j--;
	while (i > 0 && j > 0 && (st1[i] == st2[j]))
	{
		i--;
		j--;
	}
	if (st1[i] > st2[j])
		return (1);
	else if (st1[i] < st2[j])
		return (-1);
	else
		return (0);
}

void	copy_pwd(char *next_pwd, char *pwd, char *dst)
{
	int			i;
	int			j;
	static char	*tmp;

	i = 0;
	j = 0;
	while (pwd != NULL && pwd[j])
	{
		dst[j] = pwd[j];
		j++;
	}
	dst[j] = '/';
	j++;
	while (next_pwd[i])
	{
		dst[j] = next_pwd[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	chdir(dst);
	pwd = getcwd(NULL, 0);
	g_exit_code = 0;
	if (ft_strrcmp(pwd, next_pwd) != 0 && ft_strncmp(next_pwd, "..", 2) != 0 && ft_strcmp(next_pwd, ".") != 0)
	{
		printf("minishell: cd: %s: No such file or directory", next_pwd);
		g_exit_code = 1;
	}
}

void	ft_cd_secur(char *next_pwd, char *pwd)
{
	char	*dst;

	dst = malloc_dst((ft_strlen(next_pwd) + ft_strlen(pwd)));
	if (dst == NULL)
	{
		return ;
	}
	if (next_pwd != NULL)
	{
		copy_pwd(next_pwd, pwd, dst);
	}
}

void	ft_cd(t_env *env, t_node *node)
{
	char	*pwd;

	if (node->full_cmd[1] != NULL)
	{
		pwd = getcwd(NULL, 0);
		ft_cd_secur(node->full_cmd[1], pwd);
	}
	else
	{
		while (env != NULL)
		{
			if (ft_strcmp("HOME", env->attribut) == 0)
			{
				pwd = NULL;
				ft_cd_secur(env->content, pwd);
				g_exit_code = 0;
				return ;
			}
			env = env->next;
		}
		g_exit_code = 1;
		printf("minishell: cd: HOME not set\n");
	}
}
