/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:27 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/27 14:10:36 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_printf.h"
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_sign
{
	int		g_control;
	char	*tmp;
}				t_sign;

int	g_exit_code;

/* lexer */

char	check_sep(char c, char *charset);
void	free_stack(t_stack *stack);
void	printf_node(t_stack *stack);
void	lexer(t_stack *stack, char *line, int start, t_env *envp);
int		lexer_suite(t_stack *stack, char *line, int start, int i);
int		lexer_suite2(t_stack *stack, char *line, int start, int i);

/*-------*/

/* heredoc */

void	heredoc(t_stack *stack);
void	create_here_doc(char *str, char *infile);
void	multi_heredoc(t_stack *stack, char *line, int i, int pipe);
int		ft_count_heredoc(t_stack *stack);
void	ft_node_in(t_stack *stack, int pipe, char *infile, int i);
void	delete_heredoc(t_stack *stack, int count);
void	multi_heredoc2(t_stack *stack, char *infile, int i);

/*--------*/

/* parser */

void	ft_parser(t_stack *stack, t_env *env);
int		ft_checkpath(char **str);
char	*ft_path(char *line, t_env *lst_env);
char	*ft_path2(char **str, char *str2);
void	ft_checknode(t_stack *stack);
t_node	*ft_flagcheck(t_node *node);
void	ft_free_all(char **str);
void	ft_bultincheck(t_node *node);
void	ft_parser2(t_stack *stack, t_env *list_env);
void	ft_finish_node(t_stack *stack, char *in, char *out, int i);
void	ft_suite_node(t_stack *stack, char *in, char *out, int i);
void	ft_clear_all(t_stack *stack);
void	ft_checkflag0(t_stack *stack, int i);
void	ft_checkcmd(t_stack *stack);
void	ft_clear_all_suite(t_stack *stack);
void	ft_clear_all_annexe(t_stack *stack, char *tmp, t_node *tmp3, t_node *node);

/*-------*/

/* exec */

int		ft_countcmd(t_stack *stack);
int		exec(t_stack *stack, t_env *envp);
void	ft_check_fd(t_node *node);
int		multi_cmd(t_stack *stack, t_env *env);
void	ft_use_bultin(t_node *node, t_env *env);
int		simple_cmd(t_node *node, int in_pipe, int out_pipe, t_env *env);
int		multi_cmd2(t_node *node, int pipe[2], int prev_fd, t_env *env);
void	ft_perror(void);

/*-------*/

/*signaux*/

void	ft_control(void);
void	sig_for_ctrl_c(int signal);
void	sig_for_ctrl_back_slash(int signal);
void	rl_replace_line(const char *text, int clear_undo);

/*-------*/

/*=======BULTINS=======*/

void	ft_echo(t_node *node);
void	ft_cd(t_env *env, t_node *node);
void	ft_pwd(void);
void	ft_exit(void);
void	ft_export(t_env *env, t_node *node);
void	printf_export(t_env *list_env);
void	printf_env(t_env *list_env);
void	ft_unset(t_env *env, t_node *node);

/*bultins utils*/
int		ft_strcmp(char *st1, char *st2);
int		check_char(char *str, char c);
char	*ft_strchr2(const char *s, int c);
char	*ft_strcpy2(char *str, char c);
int		ft_strcmp_before_char(char *st1, char *st2, char c);
char	**list_to_matrix(t_env *env);
char	**trie_asci(char **matrix);
/*-------------*/

void	ft_expend(t_stack *stack, t_env *env);

/*======================*/

#endif
