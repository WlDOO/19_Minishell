/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:43:47 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/05 22:28:52 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_pwd(char **matrix, t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (matrix[i])
	{
		if (ft_strncmp(matrix[i], "PWD", 3) == 0)
		{
			break ;
		}
		i++;
	}
	if (matrix[i] == NULL)
	{
		while (env->next != NULL)
			env = env->next;
		tmp = malloc(sizeof(t_env));
		if (!tmp)
			return ;
		tmp->content = ft_strdup(getcwd(NULL, 0));
		tmp->attribut = ft_strdup("PWD");
		tmp->flag = 1;
		tmp->next = NULL;
		env->next = tmp;
	}
}

void	check__(char **matrix, t_env *env)
{
	int		i;
	char	*tmp2;
	char	*tmp3;
	t_env	*tmp;

	tmp2 = ft_strdup("/Users/najeuneh/Desktop/cursus");
	tmp3 = ft_strdup("/minishell-42-sami-nat/./minishell");
	i = -1;
	while (matrix[++i])
		if (ft_strcmp(matrix[i], "_") == 0)
			break ;
	if (matrix[i] == NULL)
	{
		while (env->next != NULL)
			env = env->next;
		tmp = malloc(sizeof(t_env));
		if (!tmp)
			return ;
		tmp->content = ft_strjoin(tmp2, tmp3);
		tmp->attribut = ft_strdup("_");
		tmp->flag = 1;
		tmp->next = NULL;
		env->next = tmp;
	}
	free (tmp3);
}
