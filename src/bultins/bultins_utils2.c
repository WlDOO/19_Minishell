/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:30:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 20:32:57 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*malloc_dst(int len)
{
	char	*dst;

	dst = malloc(sizeof(char) * (len + 2));
	if (!dst)
		return (NULL);
	return (dst);
}

int	ft_strrcmp(char *st1, char *st2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st1[i])
		i++;
	while (st2[j])
		j++;
	j--;
	i--;
	if (st2[j] == '/')
		j--;
	while (i > 0 && j > 0 && (st1[i] == st2[j]))
	{
		i--;
		j--;
	}
	if (st1[i] > st2[j])
		return (1);
	else if (st1[i] < st2[j])
		return (-1);
	else
		return (0);
}
