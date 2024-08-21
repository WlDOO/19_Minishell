/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:11:06 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/21 18:24:56 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_echo(t_node *node)
{
	if (ft_strcmp(node->full_cmd[1], "-n") == 0)
		printf("%s", node->full_cmd[2]);
	else
		printf("%s\n", node->full_cmd[1]);
}
