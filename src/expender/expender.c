/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:30:18 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/10 22:02:51 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int check_quote_not_open(char *str)
{
	echo 
}

void	ft_expend(t_stack *stack, t_env *env)
{
	// int		count;
	// char	*first_sep;
	t_node	*str;

	str = stack->up;
	g_exit_code = 0;
	while (str)
	{
		printf("str = %s\n", str->content);
		
		if (check_if_dollard(str->content) == 1)
			if_or_not_convert(str, env);
		ft_split_cot(str);
		str = str->next;
	}
	return ;
}
