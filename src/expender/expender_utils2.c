/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:30:31 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/10 19:33:37 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	verif_char_special(char *str, t_node *next)
{
	int	i;

	i = 0;
	(void)next;
	while (str[i])
		i++;
	if (str[i - 1] == '/')
		return (0);
	if (ft_strncmp(str, "..", 2) == 0)
		return (0);
	if (ft_strcmp(str, ".") == 0)
		return (0);
	if (ft_strcmp(str, "~") == 0)
		return (0);
	if (ft_strcmp(str, "_") == 0)
		return (0);
	return (1);
}
