/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:24:06 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/30 14:19:00 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

char	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strs_malloc(char *str, char *charset)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (check_sep(str[i], charset) == 1)
		{
			w++;
			while (str[i] && check_sep(str[i], charset) == 1)
				i++;
		}
		else
			i++;
	}
	return (w);
}

int	ft_word_malloc(char *str, char *charset, int word)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset) == 0)
			i++;
		if (word == 0)
		{
			while (str[i] && check_sep(str[i], charset) == 1)
			{
				i++;
				c++;
			}
			return (c);
		}
		while (str[i] && check_sep(str[i], charset) == 1)
			i++;
		word--;
	}
	return (c);
}

char	*ft_write_word(char *str, char *charset, char *strs, int word)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset) == 0)
			i++;
		if (word == 0)
		{
			while (str[i] && check_sep(str[i], charset) == 1)
			{
				strs[x] = str[i];
				i++;
				x++;
			}
			strs[x] = '\0';
			return (strs);
		}
		while (str[i] && check_sep(str[i], charset) == 1)
			i++;
		word--;
	}
	return (strs);
}

char	**ft_split_multi(char *str, char *charset)
{
	char	**strs;
	int		word;
	int		i;
	int		size;

	i = 0;
	size = ft_strs_malloc(str, charset);
	strs = malloc((size + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (i < size)
	{
		word = ft_word_malloc(str, charset, i);
		strs[i] = malloc((word + 1) * sizeof(char));
		if (strs[i] == NULL)
			return (NULL);
		strs[i] = ft_write_word(str, charset, strs[i], i);
		i++;
	}
	strs[size] = 0;
	return (strs);
}
/*
#include <stdio.h>
int    main()
{
    int    i;
    i = -1;
    char *sep = "  ";
    char *str = "                  dsad                    ";
    char **strs;
    strs = ft_split(str, sep);
    while(strs[++i])
    {
        printf("%s\n", strs[i]);
    }
}
*/
