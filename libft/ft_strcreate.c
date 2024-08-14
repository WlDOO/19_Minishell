/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:54:38 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/12 19:03:12 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strcreate(char *line, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (line == NULL)
		return (NULL);
	str = malloc((end - start) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = line[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
