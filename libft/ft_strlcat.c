/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:03:55 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:13 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t				i;
	unsigned int		j;
	size_t				len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	if (!dst || dstsize == 0)
		return (ft_strlen(src));
	while (dst[j])
		j++;
	while (src[i] && (j + 1) < dstsize && ((dstsize - j) - 1 > i))
	{
		dst[j + i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[j + i] = '\0';
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
		return (j + ft_strlen(src));
}
// int	main()
// {
// 	char	dest[15] = "rrrrrr";

// 	dest[14] = 'a';
// 		printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// }
