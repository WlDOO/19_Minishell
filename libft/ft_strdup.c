/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:11:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/14 16:31:22 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	char	*cpy;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	str = (char *)s1;
	cpy = malloc((ft_strlen(str)) * sizeof(char) + 1);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
