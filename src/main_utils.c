/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:39:46 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 20:41:00 by sadegrae         ###   ########.fr       */
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
