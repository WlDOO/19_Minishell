/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:52:01 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:55 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *st1, char *st2)
{
	int		i;

	i = 0;
	while (st1[i] && st2[i] && (st1[i] == st2[i]))
		i++;
	if (st1[i] > st2[i])
		return (1);
	else if (st1[i] < st2[i])
		return (-1);
	else
		return (0);
}
