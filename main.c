/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/31 17:41:25 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minishell.h"

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

void	printf_node(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		printf("// %s //\n", node->content);
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

int	main(void)
{
	char	*line;
	t_stack	*stack;
	t_sign *flag;

	stack = NULL;
	stack = ft_init_dl(stack);
	flag = malloc(sizeof(t_sign));
	ft_control();
	while (1)
	{
		line = readline("minishell$ ");
		if  (line == NULL)
		{
			rl_on_new_line();
			printf("exit");
			exit(1);
		}
		lexer(stack, line, 0);
		add_history(line);
		printf_node(stack);
		free_stack(stack);
	}
}
