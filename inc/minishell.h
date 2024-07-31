/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:27 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/31 17:27:58 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <termios.h>
# include "libft.h"
# include "pipex.h"
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_sign
{
	int g_control;
	char *tmp;
}				t_sign;

void	free_stack(t_stack *stack);
void	printf_node(t_stack *stack);
void	lexer(t_stack *stack, char *line, int start);
int		lexer_suite(t_stack *stack, char *line, int start, int i);
int		lexer_suite2(t_stack *stack, char *line, int start, int i);
char	**ft_split_multi(char *str, char *charset);

/*signaux*/

void	ft_control(void);
void sig_for_ctrl_c(int signal);
void sig_for_ctrl_back_slash(int signal);

/*-------*/
#endif
