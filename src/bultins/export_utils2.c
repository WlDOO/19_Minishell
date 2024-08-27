/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:14:39 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/26 18:15:46 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	isaldigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	verif_not_aldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (isaldigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
