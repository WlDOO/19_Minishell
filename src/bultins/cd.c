/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:08 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/14 20:00:30 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


char	*malloc_dst(int len)
{
	char *dst;

	dst = malloc(sizeof(char) * (len + 2));
	if (!dst)
		return (NULL);
	return (dst);
}

void	copy_pwd(char *next_pwd, char *pwd, char *dst)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	printf("pwd: %s\n", pwd);
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
	printf("pwd after chdir: %s\n", pwd);
}

void ft_cd_secur(char *next_pwd, char *pwd)
{
	char	*dst;
	
	dst = malloc_dst((ft_strlen(next_pwd) + ft_strlen(pwd)));
	if (dst == NULL)
		return ;
	if (next_pwd != NULL)
		copy_pwd(next_pwd, pwd, dst);
}

void ft_cd(t_env *env, t_node *node)
{
	char 	*pwd;

	printf("node;%s\n", node->content);
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
				return ;
			}
			env = env->next;
		}
		printf("minishell: cd: HOME not set\n");
	}
}
