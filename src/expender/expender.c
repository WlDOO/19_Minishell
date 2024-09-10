/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/10 19:58:57 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


void	ft_expend(t_stack *stack, t_env *env)
{
	// int		count;
	// char	*first_sep;
	t_node	*str;

	str = stack->up;
	g_exit_code = 0;
	(void)env;
	while (str)
	{

		ft_split_cot(str);
		str = str->next;
	}
	return ;
}
