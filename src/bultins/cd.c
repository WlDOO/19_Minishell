/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:08 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:49 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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