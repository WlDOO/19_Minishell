/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:18 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*ldst;
	char			*lsrc;
	size_t			lsize;
	size_t			i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	ldst = (char *)dst;
	lsrc = (char *)src;
	lsize = ft_strlen(lsrc);
	if (lsize == 0)
	{
		ldst[i] = '\0';
		return (0);
	}
	if (lsize <= 0)
		return (0);
	while (i < dstsize - 1 && lsrc[i])
	{
		ldst[i] = lsrc[i];
		i++;
	}
	ldst[i] = '\0';
	return (lsize);
}
