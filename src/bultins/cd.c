/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:08 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 22:45:20 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	copy_pwd(char *next_pwd, char *pwd, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (pwd != NULL && pwd[++j])
		dst[j] = pwd[j];
	dst[j++] = '/';
	while (next_pwd[i])
	{
		dst[j] = next_pwd[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (access(dst, F_OK) == 0)
		chdir(dst);
	pwd = getcwd(NULL, 0);
	if (ft_strrcmp(pwd, next_pwd) != 0 && ft_strncmp(next_pwd, "..", 2) != 0
		&& ft_strcmp(next_pwd, ".") != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
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

void	add_oldpwd(t_env *env, char	*pwd)
{
	t_env	*tmp;

	while (env->next)
	{
		if (ft_strcmp("OLDPWD", env->attribut) == 0)
		{
			env->content = pwd;
			return ;
		}
		env = env->next;
	}
	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	tmp->content = ft_strdup(pwd);
	tmp->attribut = ft_strdup("OLDPWD");
	tmp->flag = 1;
	tmp->next = NULL;
	env->next = tmp;
	env = env->next;
}

void	cd_suite(char *pwd, t_node *node, t_env *env)
{
	if (ft_strcmp(node->full_cmd[1], "-") == 0)
	{
		while (env != NULL)
		{
			if (ft_strcmp("OLDPWD", env->attribut) == 0)
			{
				pwd = NULL;
				ft_cd_secur(env->content, pwd);
				g_exit_code = 0;
				return ;
			}
			env = env->next;
		}
		printf("minishell: cd: OLDPWD not set");
		return ;
	}
	ft_cd_secur(node->full_cmd[1], pwd);
}

void	ft_cd(t_env *env, t_node *node)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (node->full_cmd[1] != NULL)
	{
		cd_suite(NULL, node, env);
		add_oldpwd(env, pwd);
		add_pwd(env, NULL);
	}
	else
	{
		while (env != NULL)
		{
			if (ft_strcmp("HOME", env->attribut) == 0)
			{
				ft_cd_secur(env->content, NULL);
				add_oldpwd(env, pwd);
				add_pwd(env, NULL);
				return ;
			}
			env = env->next;
		}
		g_exit_code = 1;
		printf("minishell: cd: HOME not set\n");
	}
}
