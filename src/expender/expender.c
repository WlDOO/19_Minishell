/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/08/21 17:53:43 by najeuneh         ###   ########.fr       */
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


int count_guillmet(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
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
		else if ((ft_isalnum(str[i]) == 1 || str[i] == '$') &&  ft_isalnum(str[len]) == 1)
			return (i);
		else if (str[i] == '-')
			return (-2);
		else 
			return (-1);
	}
	return (-2);
}

char	*ft_strcpy3(char *str)
{
	int	i;
	char *dst;
	
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

char	*check_sort_guillmet(char *str)
{
	int i;
	int first;
	int len;
	char *dest;
	
	i = 0;
	len = 0;
	first = 0;
	while (str[len + 1])
		len++;
	while (ft_isalnum(str[i]) == 0)
	{
		if (str[i] == 39 && str[i + 1] != 39 && ft_isalnum(str[i + 1]) == 0)
		{
			i++;
			if (str[1] == '$')
			{
				//dest = ft_strdup("");
				return (NULL);
			}
			while (str[i] != 39)
			{
				if (ft_isalnum(str[i]) == 1 || str[i] == '$')
				{
					return (dest);
				}
				if (first++ == 0)
					dest = ft_strdup("\"");
				else
				{
					dest = ft_strjoin_expend(dest, "\"");
				}
				i++;
			}
		}
		else if (str[i] == '"' && str[i + 1] != '"' && ft_isalnum(str[i + 1]) == 0)
		{
			i++;
			if (str[i] == '$')
			{
				//dest = ft_strdup("");
				return (NULL);
			}
			while (str[i] != '"')
			{
				if (ft_isalnum(str[i]) == 1 || str[i] == '$')
				{
					return (dest);
				}
				if (first++ == 0)
					dest = ft_strdup("\'");
				else
				{
					dest = ft_strjoin_expend(dest, "\'");
				}
				i++;
			}
		}
		else if (str[i] == '"' && str[i + 1] == '"' && str[i + 2] != '"' && ft_isalnum(str[i + 2]) == 0 && str[i + 2] == '$')
			i++;
		else if (str[i] == '\'' && str[i + 1] == '\'' && str[i + 2] != '\'' && ft_isalnum(str[i + 2]) == 0 && str[i + 2] == '$')
			i++;
		i++;
	}
	if (first == 0)
		return (NULL);
	return (dest);
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

int last_compare(char *str, char *sep)
{
	int i;
	int count;

	i = 0;
	(void)str;
	while (sep[i] && sep[i] == 39)
		i++;
	if (!sep[i])
	{
		if (i != 0 && i % 2 == 0)
		{
			return (1);
		}
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
	{
		return (1);
	}
	return (0);
}

char  *check_dollar(char *str, t_env *env, char *first_sep)
{
	int i;
	char *sep;
	char *str2;
	
	i = 0;
	if (check_char(str, '$') == 0)
	{
		return(str);
	}
	else if ((str[i] == 39 || str[i] == '"') && last_compare(str, first_sep) == 1)
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
				env = env->next;
			}
		}
		return (str);
	}
	return (str);
}

char *check_first_sep(char *str)
{
	int i;
	char *dest;
	
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

char *check_dollar_interrogation(char *str)
{
	int i;
	char *dest;
	
	i = 0;
	while (str[i] != '$')
		i++;
	i++;
	if (str[i] == '?')
	{
		dest = ft_itoa(g_exit_code);
		return (dest);
	}
	return (str);
}

void	ft_expend(t_stack *stack, t_env *env)
{
	int count;
	char *dest;
	char *sep;
	char *first_sep;
	t_node	*str;

	if (stack->up->next == NULL)
		return ;
	str = stack->up;
	str = str->next;
	count = count_guillmet(str->content);
	first_sep = check_first_sep(str->content);
	if (count == -2) /*il y a que des guillmet donc doit rien faire*/
		return ;
	if (count == -1) /*doit retourner une nouvelle ligne avec >*/
	{
		printf("minishell: syntax error: unexpected end of file\n");
		return ;
	}
	if (count != 0)
	{
		sep = check_sort_guillmet(str->content);
		dest = ft_strjoin_expend(sep ,ft_strcpy3(str->content + count));
		sep = check_sort_guillmet(str->content);
		if (sep)
			sep = ft_strrev(sep);
		dest = ft_strjoin_expend(dest, sep);
		dest = check_dollar(dest, env, first_sep);
		free(str->content);
		str->content = dest;
		count = count_guillmet(str->content);

		if (last_compare(str->content, first_sep) == 1 && (sep == NULL || str->content[count - 1] == 39))
		{
			while (env != NULL)
			{
				if (ft_strcmp(str->content + 1 + count, env->attribut) == 0)
				{
					str->content = env->content;
					return ;
				}
				env = env->next;
			}
			str->content = check_dollar_interrogation(str->content);
			return ;
		}
		//str->content = check_dollar_interrogation(str->content);
		str->content = dest;
		return ;
	}
	else
	{
		if (str->content[0] != '$')
		{
			return ;
		}
		while (env != NULL)
		{
			if (ft_strcmp(str->content + 1, env->attribut) == 0)
			{
				str->content = env->content;
				return ;
			}
			env = env->next;
		}
		str->content = check_dollar_interrogation(str->content);
	}
	return ;
}
