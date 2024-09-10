/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:48:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:29 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*find;

	str = (char *)haystack;
	find = (char *)needle;
	i = 0;
	if (needle[i] == '\0')
		return (str);
	while (str[i] != '\0' && i <= len)
	{
		j = 0;
		if (str[i] == find[j])
		{
			while (str[i + j] == find[j] && (i + j) < len)
			{
				j++;
			}
			if (find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
// int	main()
// {
// 	char *test = "lorem ipsum dolor sit amet";
// 	printf("strlen %zu\n", ft_strlen(test));
// 	const char *str;
// 	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 28)))
//         printf("NULL");
//     else
//         printf("%s\n", str);
// }