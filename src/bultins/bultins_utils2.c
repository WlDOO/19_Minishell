/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:30:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 22:43:06 by sadegrae         ###   ########.fr       */
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
	while (st1 && st1[i])
		i++;
	while (st2 && st2[j])
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
	if (st1 && st2 && st1[i] > st2[j])
		return (1);
	else if (st1 && st2 && st1[i] < st2[j])
		return (-1);
	else
		return (0);
}

void	add_pwd(t_env *env, char	*pwd)
{
	t_env	*tmp;

	pwd = getcwd(NULL, 0);
	while (env->next)
	{
		if (ft_strcmp("PWD", env->attribut) == 0)
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
	tmp->attribut = ft_strdup("PWD");
	tmp->flag = 1;
	tmp->next = NULL;
	env->next = tmp;
	env = env->next;
	g_exit_code = 0;
}
