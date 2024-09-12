/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:39:46 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 17:52:06 by najeuneh         ###   ########.fr       */
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
	size_t	i;
	char	*str;

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

void	ft_print(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	while (node != NULL)
	{
		printf("content = %s flag = %d %s %d\n", node->content,
			node->flag, node->in, node->append);
		node = node->next;
	}
}
