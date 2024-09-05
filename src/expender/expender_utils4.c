/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:36:07 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 20:36:32 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*copy_without_char(char *str, char c)
{
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	i = 0;
	tmp = malloc(sizeof(char) * ((ft_strlen(str) - count_char(str, c)) + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

void	expend_verif(t_env *env, int count, t_node *str, char *first_sep)
{
	if (count == -2)
		return ;
	if (count == -1)
	{
		if (check_char(str->content, '"') == 1 || check_char(str->content,
				'\'') == 1)
		{
			if (check_char(str->content, '"') == 1)
			{
				str->content = copy_without_char(str->content, '"');
			}
			else
				str->content = copy_without_char(str->content, '\'');
		}
		if (check_char(str->content, '=') == 1)
			return ;
		printf("minishell: syntax error: unexpected end of file\n");
		g_exit_code = -1;
		return ;
	}
	if (count != 0)
		expend_if_dollard(env, str, first_sep, count);
	else
		expend_ifnot_dollard(env, str);
}
