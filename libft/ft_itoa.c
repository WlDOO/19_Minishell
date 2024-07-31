/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:44:33 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:24:44 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_count2(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i ++;
	}
	if (n < 10 && n >= 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	nb = n;
	str = malloc(ft_count2(nb) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = ft_count2(n) - 1;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	else
	{
		while (nb > 0)
		{
			str[i--] = (nb % 10) + 48;
			nb = nb / 10;
		}
	}
	return (str[ft_count2(n)] = '\0', str);
}

// int	main()
// {
// 	printf("%s\n", ft_itoa(-9));
// }
