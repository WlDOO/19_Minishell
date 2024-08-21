/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:22 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/21 18:05:18 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	not_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
		{
			g_exit_code = 255;
			printf("exit\n");
			exit(g_exit_code);
		}
		i++;
	}
}

void	ft_exit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 2)
	{
		not_alpha(str[1]);
		if (ft_atoi(str[1]) <= 9223372036854775806)
		{
			g_exit_code = (ft_atoi(str[1]) % 256);
			printf("exit\n");
			exit(g_exit_code);
		}
	}
	g_exit_code = 255;
	printf("exit\n");
	exit(g_exit_code);
}
