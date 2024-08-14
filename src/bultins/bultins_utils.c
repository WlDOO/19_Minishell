/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:52:01 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/06 14:36:29 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*return 1 si il a trouver le charactere sion return 0*/
int	check_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *st1, char *st2)
{
	int		i;

	i = 0;
	while (st1[i] && st2[i] && (st1[i] == st2[i]))
		i++;
	if (st1[i] > st2[i])
		return (1);
	else if (st1[i] < st2[i])
		return (-1);
	else
		return (0);
}

int	ft_strcmp_before_char(char *st1, char *st2, char c)
{
	int		i;

	i = 0;
	while (st1[i] && st2[i] && (st1[i] == st2[i]) && st1[i] != c)
		i++;
	if (st2[i] == '\0' && st1[i] == c)
		return (0);
	else if (st2[i] == c)
		return (1);
	else
		return (-1);
}

char	**trie_asci(char **matrix)
{
	int		i;
	char	*swp;
	int len;
	
	i = 0;
	len = 0;
	while (matrix[len])
		len++;
	//printf("matrix1:%s\nmatrix2:%s\n", matrix[i], matrix[i + 1]);
	while (i < len - 1)
	{
		if (ft_strcmp(matrix[i], matrix[i + 1]) > 0)
		{
			swp = matrix[i];
			matrix[i] = matrix[i + 1];
			matrix[i + 1] = swp;
			i = -1;
		}
		i++;
	}
	return (matrix);
}