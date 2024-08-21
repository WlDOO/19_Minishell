/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:11:06 by sadegrae          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/08/20 13:55:29 by najeuneh         ###   ########.fr       */
=======
/*   Updated: 2024/08/19 18:33:07 by sadegrae         ###   ########.fr       */
>>>>>>> suite_expender
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

<<<<<<< HEAD

void	ft_echo(t_node *node)
{
	if (ft_strncmp(node->full_cmd[1], "-n", 2) == 0)
		printf("%s", node->full_cmd[2]);
	else
		printf("%s\n", node->full_cmd[1]);
=======
void	ft_echo(t_node *node)
{
	node = node->next;
	if (node != NULL)
		printf("%s\n", node->content);
	printf("\n");
>>>>>>> suite_expender
}
