/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:30:31 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/05 17:21:33 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*check_first_sep(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '$' && ft_isalnum(str[i]) == 0)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '$' && ft_isalnum(str[i]) == 0)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*check_dollar_interrogation(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] != '$')
		i++;
	i++;
	if (str[i] == '?')
	{
		printf("g_exit_code %d\n", g_exit_code);
		dest = ft_itoa(g_exit_code);
		g_exit_code = 0;
		return (dest);
	}
	return (str);
}

char	*return_env_if_dollar(char *str2, char *str, char *sep, int i)
{
	if (str[0] == '"')
		sep = ft_strdup("\"");
	else
		sep = ft_strdup("'");
	i--;
	if (i >= 1)
	{
		while (i >= 1)
		{
			if (str[i] == '"')
				sep = ft_strjoin_expend(sep, ft_strdup("\""));
			else
				sep = ft_strjoin_expend(sep, ft_strdup("'"));
			i--;
		}
	}
	sep = ft_strrev(sep);
	str = ft_strjoin_expend(str2, sep);
	sep = ft_strrev(sep);
	str = ft_strjoin_expend(sep, str);
	return (str);
}

char	*check_dollar(char *str, t_env *env, char *first_sep, int i)
{
	char	*sep;
	char	*str2;

	sep = NULL;
	if (check_char(str, '$') == 0)
		return (str);
	else if ((str[i] == 39 || str[i] == '"') && last_compare(first_sep) == 1)
	{
		while (str[i] != '$')
			i++;
		if (str[i - 1] == 39 || str[i - 1] == '"')
		{
			while (env != NULL)
			{
				if (ft_strcmp(ft_strcpy3(str + i + 1), env->attribut) == 0)
				{
					str2 = ft_strdup(env->content);
					return (return_env_if_dollar(str2, str, sep, i));
				}
				env = env->next;
			}
		}
		return (str);
	}
	return (str);
}

int	verif_char_special(char *str, t_node *next)
{
	int	i;

	i = 0;
	(void)next;
	while (str[i])
		i++;
	if (str[i - 1] == '/')
		return (0);
	if (ft_strncmp(str, "..", 2) == 0)
		return (0);
	if (ft_strcmp(str, ".") == 0)
		return (0);
	if (ft_strcmp(str, "~") == 0)
		return (0);
	return (1);
}
