/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:52:15 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/03 14:47:01 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strjoin_expend(char *st1, char *st2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!st1)
		return (st2);
	if (!st2)
		return (st1);
	str = malloc((ft_strlen(st1) + ft_strlen(st2)) * sizeof(char *) + 1);
	if (str == NULL)
		return (free(st1), NULL);
	while (st1[i])
	{
		str[i] = st1[i];
		i++;
	}
	while (st2[j])
	{
		str[i + j] = st2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(st1), str);
}

char	*ft_strcpy3(char *str)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] != '\0' && (str[i] != 39 && str[i] != '"'))
		i++;
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] && (str[i] != 39 && str[i] != '"'))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strrev(char *str)
{
	int		j;
	int		i;
	char	tmp;

	j = 0;
	while (str[j] != '\0')
		j++;
	j--;
	i = 0;
	while (((j + 1) / 2) > i)
	{
		tmp = str[i];
		str[i] = str[j - i];
		str[j - i] = tmp;
		i++;
	}
	return (str);
}

int	count_guillmet(char *str, int i, int len)
{
	if (str[i] == '$')
		return (0);
	while (str[len + 1])
		len++;
	while (i <= len)
	{
		if (str[i] == '\"' && str[len] == '\"')
		{
			i++;
			len--;
		}
		else if (str[i] == '\'' && str[len] == '\'')
		{
			i++;
			len--;
		}
		else if ((ft_isalnum(str[i]) == 1 || str[i] == '$') && ft_isalnum(str[len]) == 1)
			return (i);
		else if (str[i] == '-' || str[i] == '|')
			return (-2);
		else
			return (-1);
	}
	return (-2);
}

int	last_compare(char *sep)
{
	int	i;
	int	count;

	i = 0;
	while (sep[i] && sep[i] == 39)
		i++;
	if (!sep[i])
	{
		if (i != 0 && i % 2 == 0)
			return (1);
		return (0);
	}
	i = 0;
	while (sep[i])
		i++;
	i--;
	count = 0;
	while (sep[i] == 39 && i >= 0)
	{
		count++;
		i--;
	}
	if (count % 2 == 0)
		return (1);
	return (0);
}
