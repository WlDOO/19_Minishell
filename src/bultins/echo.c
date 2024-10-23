/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:11:06 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/19 16:50:49 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_n(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		else if (str[i] != 'e' && str[i] != 'n')
			return (1);
		i++;
	}
	if (count == 1)
		return (0);
	return (1);
}

void	ft_echo(t_node *node)
{
	int	i;

	i = 1;
	if (!ft_strncmp(node->full_cmd[1], "-n", 2) && !count_n(node->full_cmd[1]))
	{
		while (node->full_cmd[++i] != NULL)
		{
			if (node->full_cmd[i + 1] == NULL)
				printf("%s", node->full_cmd[i]);
			else
				printf("%s ", node->full_cmd[i]);
		}
	}
	else
	{
		while (node->full_cmd[i] != NULL)
		{
			if (node->full_cmd[i + 1] == NULL)
				printf("%s\n", node->full_cmd[i]);
			else
				printf("%s ", node->full_cmd[i]);
			i++;
		}
	}
}
