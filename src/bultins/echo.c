/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:11:06 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/14 15:57:20 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int count_guillmet(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[len + 1])
		len++;
	while (i <= len)
	{
		if (str[i] == '\"' && str[len] == '\"')
		{
			i++;
			len--;
		}
		else if (str[i] == '\'' && str[len] == '\'')
		{
			i++;
			len--;
		}
		else if (ft_isalnum(str[i]) == 1 &&  ft_isalnum(str[len]) == 1)
			return (i);
		else 
			return (-1);
	}
	return (-2);
}

char	*ft_strcpy3(char *str)
{
	int	i;
	char *dst;
	
	i = 0;
	while (str[i] != '\0' && (str[i] != 39 && str[i] != '"'))
		i++;
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] && (str[i] != 39 && str[i] != '"'))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_expend(t_stack *stack)
{
	int count;
	char *dest;
	t_node	*str;

	str = stack->up;
	str = str->next;
	count = count_guillmet(str->content);
	if (count == -2) /*il y a que des guillmet donc doit rien faire*/
		printf("COUNT -2\n");
	if (count == -1) /*doit retourner une nouvelle ligne avec >*/
		printf("COUNT -1\n");
	dest = ft_strcpy3(str->content + count);
	printf("dest :%s\n", dest);
	return ;
}

void	ft_echo(t_stack *stack)
{
	t_node	*node;

	node = stack->up;
	node = node->next;
	if (node != NULL)
		printf("%s\n", node->content);
}
