/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/30 19:04:01 by najeuneh         ###   ########.fr       */
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
		ft_printf("// %s //\n", node->content);
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

	stack = NULL;
	stack = ft_init_dl(stack);
	while (1)
	{
		line = readline("minishell$ ");
		lexer(stack, line, 0);
		add_history(line);
		printf_node(stack);
		free_stack(stack);
	}
}
