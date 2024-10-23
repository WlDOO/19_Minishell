/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:22 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/11 15:03:56 by najeuneh         ###   ########.fr       */
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
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(g_exit_code);
		}
		i++;
	}
}

void	ft_exit(char **str, int i)
{
	if (str[1] == NULL)
	{
		printf("exit\n");
		exit(g_exit_code);
	}
	if (str[2] != NULL)
	{
		g_exit_code = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
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
