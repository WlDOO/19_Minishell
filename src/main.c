/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/05 16:36:13 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_stack	*ft_init_dl(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		write(2, "Error\n", 6);
		return (stack);
	}
	stack->up = NULL;
	stack->low = NULL;
	return (stack);
}

char	*ft_strchr2(const char *s, int c)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (str[i] == (unsigned char)c)
			return (ft_strdup(&str[i + 1]));
		i++;
	}
	return (NULL);
}

char	*ft_strcpy2(char *str, char c)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] != c)
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] != c)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char **create_matrix_env()
{
	char **matrix;

	matrix = malloc(sizeof(char *) * 4);
	matrix[0] = ft_strdup("PWD=/Users/sadegrae/minishell/minishell-42-sami-nat-1");
	matrix[1] = ft_strdup("SHLVL=1");
	matrix[2] = ft_strdup("_=/usr/bin/env");
	matrix[3] = NULL;
	return (matrix);
}

void shell_level(t_env *env)
{
	t_env	*tmp;
	int count;

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
	shell_level(tmp);
	return (tmp);
}

void	printf_node(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		printf("// %s %d %d//\n", node->content, node->flag, node->bultin);
		node = node->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_stack	*stack;
	t_env	*list_env;
	t_sign	*flag;

	(void)av;
	(void)ac;
	stack = NULL;
	list_env = list_new(env, -1, NULL);
	stack = ft_init_dl(stack);
	flag = malloc(sizeof(t_sign));
	ft_control();
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			free_stack(stack);
			system("leaks minishell");
			printf("\rexit\n");
			exit(0);
		}
		lexer(stack, line, 0, list_env);
		add_history(line);
		free_stack(stack);
	}
}
