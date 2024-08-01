/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:11:06 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/01 19:14:10 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_echo(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	node = node->next;
	if (node != NULL)
		printf("%s", node->content);
	printf("\n");
}

void ft_cd(t_stack *stack)
{
	char *pwd;
	char *next_pwd;
	char	*dst;
	t_node	*node;
	int	i;
	int	j;

	i = 0;
	j = 0;
	node = stack->up;
	node = node->next;
	next_pwd = node->content;
	j = 0;
	pwd = getcwd(NULL, 0);
	j = ft_strlen(next_pwd) + ft_strlen(pwd);
	dst = malloc(sizeof(char) * (j + 2));
	if (!dst)
		return ;
	if (node != NULL)
	{
		printf("pwd: %s\n", pwd);
		while (pwd[j])
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
}

void	ft_pwd(t_stack *stack)
{
	char *pwd;
	
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
}

void	ft_exit(t_stack *stack)
{
	printf("exit\n");
	exit(0);
}

void ft_export(t_env *env, t_stack *stack)
{
	t_node	*node;
	t_env *tmp;

	tmp = malloc(sizeof(t_env*));
	node = stack->up;
	node = node->next;
	while (env->next != NULL)
		env = env->next;
	tmp->content = node->content;
	tmp->flag = 0;
	tmp->next = NULL;
	env->next = tmp;

	while (list_env != NULL)
	{
		printf("%s\n", list_env->content);
		list_env = list_env->next;
	}
}