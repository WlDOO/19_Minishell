/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:53:42 by sadegrae          #+#    #+#             */
/*   Updated: 2024/09/04 18:18:08 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig_for_ctrl_c(int signal)
{
	(void)signal;
	g_exit_code = 1;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sig_for_ctrl_back_slash(int signal)
{
	(void)signal;
	rl_redisplay();
}

void	ft_control(int count)
{
	struct termios	term;

	if (count == 0)
	{
		signal(SIGINT, sig_for_ctrl_c);
		signal(SIGQUIT, sig_for_ctrl_back_slash);
	}
	if (count == 1)
	{
		signal(SIGINT, sig_for_ctrl_c_exec);
		signal(SIGQUIT, sig_for_ctrl_back_slash_exec);
	}
	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}
