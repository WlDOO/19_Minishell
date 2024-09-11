/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/11 15:11:33 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


void	ft_expend(t_stack *stack, t_env *env)
{
	// int		count;
	// char	*first_sep;
	t_node	*str;

	str = stack->up;
	while (str != NULL)
	{
		if (check_if_dollard(str->content) == 1)
			if_or_not_convert(str, env);
		ft_split_cot(str);
		str = str->next;
	}
	return ;
}
