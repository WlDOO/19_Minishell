/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:26:30 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/13 15:59:06 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (s == NULL)
	{
		return (ft_putstr("(null)"));
	}
	while (s[i])
	{
		j += write (2, &s[i], 1);
		i++;
	}
	return (j);
}
