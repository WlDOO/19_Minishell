/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:51:05 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/27 16:40:30 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char		*pwd;
	static char	*tmp;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		tmp = pwd;
		printf("%s\n", pwd);
	}
	else if (pwd == NULL)
		printf("%s\n", tmp);
	g_exit_code = 0;
}
