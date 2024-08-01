/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:27 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/01 18:59:59 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <termios.h>
# include <sys/stat.h>
# include "libft.h"
# include "pipex.h"
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_sign
{
	int g_control;
	char *tmp;
}				t_sign;

/* lexer */

char	check_sep(char c, char *charset);
void	free_stack(t_stack *stack);
void	printf_node(t_stack *stack);
void	lexer(t_stack *stack, char *line, char **env, int start);
int		lexer_suite(t_stack *stack, char *line, int start, int i);
int		lexer_suite2(t_stack *stack, char *line, int start, int i);

/*-------*/

/* parser */

void	ft_parser(t_stack *stack);
t_node	*ft_flagcheck(t_node *node);

/*-------*/

/*signaux*/

void	ft_control(void);
void 	sig_for_ctrl_c(int signal);
void 	sig_for_ctrl_back_slash(int signal);
void	rl_replace_line(const char *text, int clear_undo);

/*-------*/

/*commande*/

void	ft_echo(t_stack *stack);
void 	ft_cd(t_stack *stack);
void	ft_pwd(t_stack *stack);
void	ft_exit(t_stack *stack);
void ft_export(t_env *env, t_stack *stack);

/*-------*/
#endif
