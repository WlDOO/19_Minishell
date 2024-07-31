/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:21:22 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/30 17:21:00 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*st1;
	char	*st2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	st2 = (char *)s2;
	st1 = (char *)s1;
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
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(st1), str);
}
