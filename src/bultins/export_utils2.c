/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:14:39 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/12 20:52:21 by sadegrae         ###   ########.fr       */
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
	else if (c == '+'|| c == '-')
		return (1);
	return (0);
}

int	isaldigit2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c == '+')
		return (1);
	return (0);
}

int	verif_not_aldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (isaldigit2(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_export(char *st1, char *st2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!st1)
		return (st2);
	if (!st2)
		return (st1);
	str = malloc((ft_strlen(st1) + ft_strlen(st2)) * sizeof(char *) + 1);
	if (str == NULL)
		return (free(st1), NULL);
	while (st1[i])
	{
		str[i] = st1[i];
		i++;
	}
	while (st2[j])
	{
		str[i + j] = st2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
