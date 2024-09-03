/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:22 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/29 11:15:16 by najeuneh         ###   ########.fr       */
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
			printf("exit\nminishell: exit: %s: numeric argument required\n",
				str);
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
	printf("exit\n");
	system("leaks minishell");
	exit(g_exit_code);
}
