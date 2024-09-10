/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:36:07 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/10 19:34:17 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	verif_middle_guil(t_node *node, int i, int len)
{
	char	*tmp;

	while (node->content[++i])
	{
		if (node->content[i] != '"' && node->content[i] != 39)
			len++;
		
	}
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return ;
	i = 0;
	len = 0;
	while (node->content[i])
	{
		if (node->content[i] != '"' && node->content[i] != 39)
			tmp[len++] = node->content[i++];
		else
			i++;
	}
	tmp[len++] = '\0';
	if (node->content != NULL && tmp != NULL)
		free(node->content);
	node->content = ft_strdup(tmp);
	if (tmp != NULL)
		free (tmp);
}


