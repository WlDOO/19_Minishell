/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:36:05 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/26 18:18:32 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	sort_single_quote(char **dest, char *str, int *i, int *first)
{
	(*i)++;
	if (str[*i] == '$')
		return (2);
	while (str[*i] != 39)
	{
		if (ft_isalnum(str[*i]) == 1 || str[*i] == '$')
			return (0);
		if (*first == 0)
		{
			*dest = ft_strdup("\"");
			(*first)++;
		}
		else
			*dest = ft_strjoin_expend(*dest, "\"");
		(*i)++;
	}
	return (1);
}

int	sort_double_quote(char **dest, char *str, int *i, int *first)
{
	(*i)++;
	if (str[*i] == '$')
		return (2);
	while (str[*i] != '"')
	{
		if (ft_isalnum(str[*i]) == 1 || str[*i] == '$')
			return (0);
		if (*first == 0)
		{
			*dest = ft_strdup("\'");
			(*first)++;
		}
		else
			*dest = ft_strjoin_expend(*dest, "\'");
		(*i)++;
	}
	return (1);
}

char	*return_for_sort(int result, char *dest)
{
	if (result == 2)
		return (NULL);
	return (dest);
}

char	*check_sort_guillmet(char *str, int i, int first, int result)
{
	char	*dest;

	while (ft_isalnum(str[++i]) == 0)
	{
		if (str[i] == 39 && str[i + 1] != 39 && ft_isalnum(str[i + 1]) == 0)
		{
			result = sort_single_quote(&dest, str, &i, &first);
			if (result == 2 || result == 0)
				return (return_for_sort(result, dest));
		}
		else if (str[i] == '"' && str[i + 1] != '"'
			&& ft_isalnum(str[i + 1]) == 0)
		{
			result = sort_double_quote(&dest, str, &i, &first);
			if (result == 2 || result == 0)
				return (return_for_sort(result, dest));
		}
		else if (str[i] == '"' && str[i + 1] == '"' && str[i + 2] != '"')
			i++;
		else if (str[i] == '\'' && str[i + 1] == '\'' && str[i + 2] != '\'')
			i++;
	}
	if (first == 0)
		return (NULL);
	return (dest);
}
