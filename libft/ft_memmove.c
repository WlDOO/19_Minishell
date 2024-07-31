/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:06:04 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:25:38 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*sdest;
	const char	*ssrc;

	ssrc = src;
	sdest = dst;
	if (dst < src)
	{
		while (len)
		{
			*sdest = *ssrc;
			sdest++;
			ssrc++;
			len--;
		}
	}
	else if (src < dst)
	{
		while (len)
		{
			sdest[len - 1] = ssrc[len - 1];
			len--;
		}
	}
	return (dst);
}

// int main ()
// {
// char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;

// 	dest = src + 1;
//     if (src != memmove(src, dest, 8))
//         write(1, "dest's adress was not returned\n", 31);
// 	printf("son %s\n", dest);
// char	src2[] = "lorem ipsum dolor sit amet";
// 	char	*dest2;

// 	dest2 = src2 + 1;
//     if (src != ft_memmove(src2, dest2, 8))
//         write(1, "2dest's adress was not returned\n", 32);
//   printf("mon %s\n", dest2);
//   return 0;
// }
