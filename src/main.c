/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/06 14:28:32 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_matrix_env(void)
{
	char	**m;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("_=/Users/najeuneh/Desktop/cursus");
	tmp2 = ft_strdup("/minishell-42-sami-nat/./minishell");
	m = malloc(sizeof(char *) * 4);
	m[0] = ft_strdup("PWD=/Users/sadegrae/minishell/minishell-42-sami-nat-1");
	m[1] = ft_strdup("SHLVL=1");
	m[2] = ft_strjoin(tmp, tmp2);
	m[3] = NULL;
	free (tmp2);
	return (m);
}

void	shell_level(t_env *env)
{
	t_env	*tmp;
	int		count;

	while (env->next != NULL)
	{
		if (ft_strcmp(env->attribut, "SHLVL") == 0)
		{
			count = ft_atoi(env->content) + 1;
			free(env->content);
			env->content = ft_itoa(count);
			return ;
		}
		env = env->next;
	}
	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return ;
	tmp->content = ft_strdup("1");
	tmp->attribut = ft_strdup("SHLVL");
	tmp->flag = 1;
	tmp->next = NULL;
	env->next = tmp;
	return ;
}

t_env	*list_new(char **matrix, int i, t_env *tmp)
{
	t_env	*new;
	t_env	*node;

	if (!matrix[0])
		matrix = create_matrix_env();
	while (matrix[++i])
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (free(tmp), NULL);
		new->content = ft_strchr2(matrix[i], '=');
		new->attribut = ft_strcpy2(matrix[i], '=');
		new->flag = 1;
		new->next = NULL;
		if (!tmp)
			tmp = new;
		else
			node->next = new;
		node = new;
	}
	check_pwd(matrix, tmp);
	shell_level(tmp);
	return (tmp);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_stack	*stack;
	t_env	*list_env;

	(void)av;
	(void)ac;
	stack = NULL;
	list_env = list_new(env, -1, NULL);
	while (1)
	{
		ft_control(0);
		stack = ft_init_dl(stack);
		line = readline("minishell$ ");
		if (line == NULL)
		{
			ft_free_env(list_env);
			printf("\rexit\n");
			free_stack(stack);
			exit(0);
		}
		lexer(stack, line, 0, list_env);
		add_history(line);
		free_stack(stack);
		free(line);
	}
}
