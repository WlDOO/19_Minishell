/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:25:32 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:37 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

	// if (start >= ft_strlen(s))
	// 	return ("");
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s[i] == '\0')
		return ("");
	if (start > len)
		return ("");
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s[start + i] && len)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
// int	main()
// {
// 	char	str[] = "";
// 	printf("%s\n", ft_substr(str, 400, 20));
// 		char *bullshit;
// 		char	*strsub;
//     if (!(strsub = ft_substr(str, 400, 20)))
//         printf("NULL");
//     else
//     {
//         bullshit = (char *)&strsub[30];
//         bullshit = "FULL BULLSHIT";
//         if (strsub)
//             printf("%s\n", strsub);
//         else
//             printf("rip");
//     }
//     if (str == strsub)
//         printf("\nA new string was not returned");
//     (void)bullshit;
// }