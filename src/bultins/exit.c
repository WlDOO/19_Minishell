/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:22 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/03 15:23:29 by najeuneh         ###   ########.fr       */
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
	if (str[1] == NULL)
	{
		printf("exit\n");
		system("leaks minishell");
		exit(g_exit_code);	
	}
	if (str[2] != NULL)
	{
		g_exit_code = 1;
		printf("exit\nminishell: exit: too many arguments\n");
		return ;
	}
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
}
