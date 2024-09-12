/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:51:05 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 22:47:57 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char		*pwd;
	static char	*tmp;

	pwd = NULL;
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
