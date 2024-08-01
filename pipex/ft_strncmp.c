/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:46:53 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/01 16:31:31 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*st1;
	char		*st2;

	st1 = (char *)s1;
	st2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] && st1[i] == st2[i] && i < n - 1)
		i++;
	if ((unsigned char)st1[i] > (unsigned char)st2[i])
		return (1);
	else if ((unsigned char)st1[i] < (unsigned char)st2[i])
		return (-1);
	else
		return (0);
}
