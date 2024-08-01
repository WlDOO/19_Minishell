/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/01 19:12:32 by sadegrae         ###   ########.fr       */
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

t_env	*list_new(char **matrix)
{
	t_env	*new;
	t_env	*node;
	t_env	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (matrix[i])
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (free(tmp), NULL);
		new->content = matrix[i];
		new->flag = 1;
		new->next = NULL;
		if (!tmp)
			tmp = new;
		else
			node->next = new;
		node = new;
		i++;
	}
	return (tmp);
}

void	printf_node(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		printf("// %s %d //\n", node->content, node->flag);
		node = node->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	{
		while (stack->up != NULL)
		{
			temp = stack->up->next;
			free(stack->up);
			stack->up = temp;
		}
		stack->up = NULL;
		stack->low = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_stack	*stack;
	t_env	*list_env;
	t_sign *flag;

	(void)av;
	(void)ac;
	stack = NULL;
	list_env = list_new(env);
	stack = ft_init_dl(stack);
	flag = malloc(sizeof(t_sign));
	ft_control();
	while (1)
	{
		line = readline("minishell$ ");
		if  (line == NULL)
		{
			printf("minishell$ exit\n");
			exit(1);
		}
		lexer(stack, line, env, 0);
		add_history(line);
		printf_node(stack);
		//ft_echo(stack);
		//ft_cd(stack);
		//ft_pwd(stack);
		//ft_exit(stack);
		ft_export(list_env, stack);
		while (list_env != NULL)
		{
			if (list_env->flag == 1)
				printf("%s\n", list_env->content);
			list_env = list_env->next;
		}
		free_stack(stack);
	}
}
