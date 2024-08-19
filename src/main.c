/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:14 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/15 14:09:32 by najeuneh         ###   ########.fr       */
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
	int	i;
	char *dst;
	
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
		new->content = ft_strchr2(matrix[i], '=');
		new->attribut = ft_strcpy2(matrix[i], '=');
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
		printf("// %s %d %d//\n", node->content, node->flag, node->bultin);
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
		if  (line == NULL || ft_strncmp(line, "exit", 4) == 0)
		{
			free_stack(stack);
			printf("\rexit\n");
			exit(1);
		}
		lexer(stack, line, env, 0,list_env);
		add_history(line);
		printf_node(stack);
		free_stack(stack);
	}
}
