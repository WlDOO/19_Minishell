/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:57:17 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/30 17:03:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_2check(char *tri, char str)
{
	int	i;

	i = 0;
	while (tri[i])
	{
		if (tri[i] == str)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char *str, char *tri)
{
	int	i;
	int	j;
	int	k;
	int	x;

	x = 0;
	i = 0;
	if (!str || !tri)
		return (0);
	j = ft_strlen(str) - 1;
	while (ft_2check(tri, str[i]) == 1)
		i++;
	k = j;
	while (ft_2check(tri, str[j]) == 1 && j >= 0)
	{
		x++;
		j--;
	}
	return (k - i - x + 1);
}

static int	ft_finish(char *str, char *tri)
{
	int	i;
	int	j;

	i = 0;
	if (!tri || !str)
		return (0);
	j = ft_strlen(str) - 1;
	while (ft_2check(tri, str[j]) == 1 && j >= 0)
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*fnsh;
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	str = (char *)s1;
	if (ft_count(str, (char *)set) <= 0)
		return (ft_strdup(""));
	j = ft_finish(str, (char *)set);
	fnsh = malloc(ft_count(str, (char *)set) + 1);
	if (!fnsh)
		return (NULL);
	while (ft_2check((char *)set, str[i]) == 1)
		i++;
	while (str[i] && i <= j)
	{
		fnsh[x++] = str[i++];
	}
	fnsh[x] = '\0';
	return (fnsh);
}
