/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:53:21 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/04 18:17:38 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig_for_ctrl_c_exec(int signal)
{
	(void)signal;
	g_exit_code = 130;
}

void	sig_for_ctrl_back_slash_exec(int signal)
{
	g_exit_code = 131;
	write(2, "Quit: 3\n", 8);
	(void)signal;
}
