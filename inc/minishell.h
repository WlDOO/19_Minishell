/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:27 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/12 18:57:52 by sadegrae         ###   ########.fr       */
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
# include <sys/stat.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_sign
{
	int		g_control;
	char	*tmp;
}				t_sign;

int	g_exit_code;

t_stack	*ft_init_dl(t_stack *stack);
char	*ft_strchr2(const char *s, int c);
char	*ft_strcpy2(char *str, char c);
void	check_pwd(char **matrix, t_env *env);
void	check__(char **matrix, t_env *env);
void	ft_print(t_stack *stack);

/* lexer */

char	check_sep(char c, char *charset);
void	free_stack(t_stack *stack);
void	lexer(t_stack *stack, char *line, int start, t_env *envp);
int		ft_lexer_expextion(char *line, int start, int i);
int		ft_lexer_expextion2(char *line, int start, int i);
void	ft_lexer2(char *line, t_stack *stack, t_node *node, t_env *envp);
void	ft_free_env(t_env *list_env);

/*-------*/

/* heredoc */

void	heredoc(t_stack *stack);
void	create_here_doc(char *str, char *infile);
void	multi_heredoc(t_stack *stack, char *line, int i, int pipe);
int		ft_count_heredoc(t_stack *stack);
void	ft_node_in(t_stack *stack, int pipe, char *infile, int i);
void	delete_heredoc(t_stack *stack, int count);
void	multi_heredoc2(t_stack *stack, char *infile, int i);
void	ft_multi_heredoc_suite(t_node *node, char *infile, int i,
			t_stack *stack);
int		ft_only_heredoc(t_stack *stack);

/*--------*/

/* parser */

void	ft_parser(t_stack *stack, t_env *env);
int		ft_checkpath(char **str);
char	*ft_path(char *line, t_env *lst_env);
char	*ft_path2(char **str, char *str2);
void	ft_checknode(t_stack *stack);
t_node	*ft_flagcheck(t_node *node);
void	ft_bultincheck(t_node *node);
void	ft_parser2(t_stack *stack, t_env *list_env);
void	ft_finish_node(t_stack *stack, char *in, char *out, int i);
void	ft_suite_node(t_stack *stack, char *in, char *out, int i);
void	ft_clear_all(t_stack *stack);
void	ft_checkflag0(t_stack *stack, int i);
void	ft_checkcmd(t_stack *stack);
void	ft_clear_all_suite(t_stack *stack);
void	ft_clear_all_annexe(t_stack *stack, char *tmp, t_node *tmp3,
			t_node *node);
void	ft_check_next(t_node **node);
void	ft_look_cmd(t_stack *stack);
void	ft_bultincheck2(t_node *node);
void	ft_check_full_path(t_node *node);
void	ft_look_append(t_stack	*stack, t_node *tmp);
void	ft_infile_out_file(t_stack *stack);
void	ft_create_out(char *content);

/*-------*/

/* exec */

int		ft_countcmd(t_stack *stack);
int		exec(t_stack *stack, t_env *envp, int status);
void	ft_check_fd(t_node *node);
int		multi_cmd(t_stack *stack, t_env *env, int *pid);
void	ft_use_bultin(t_node *node, t_env *env);
void	simple_cmd(t_node *node, int in_pipe, int out_pipe, t_env *env);
int		multi_cmd2(t_node *node, int pipe[2], int prev_fd, t_env *env);
void	ft_perror(void);
void	ft_check_out(t_node *node);
void	ft_wait(int pid, int status, int count);
void	error_manage(char *cmd);
void	parent_bultins(t_node *node, t_env *env);

/*-------*/

/*signaux*/

void	ft_control(int count);
void	sig_for_ctrl_c(int signal);
void	sig_for_ctrl_back_slash(int signal);
void	rl_replace_line(const char *text, int clear_undo);
void	ft_control_exec(void);
void	sig_for_ctrl_back_slash_exec(int signal);
void	sig_for_ctrl_c_exec(int signal);

/*-------*/

/*=======BULTINS=======*/

void	ft_echo(t_node *node);
void	ft_cd(t_env *env, t_node *node);
void	ft_pwd(void);
void	ft_exit(char **str, int i);
void	ft_export(t_env *env, t_node *node, int i);
void	printf_export(t_env *list_env);
void	printf_env(t_env *list_env);
void	ft_unset(t_env *env, t_node *node);
void	ft_cd_secur(char *next_pwd, char *pwd);
void	ft_cd_home(t_env *env);

/*bultins utils*/
int		ft_strcmp(char *st1, char *st2);
int		check_char(char *str, char c);
char	*ft_strchr2(const char *s, int c);
char	*ft_strcpy2(char *str, char c);
int		ft_strcmp_before_char(char *st1, char *st2, char c);
char	**list_to_matrix(t_env *env);
char	**trie_asci(char **matrix);
int		isaldigit(int c);
int		verif_not_aldigit(char *str);
void	ft_export_last(t_env *env, char *node);
char	*ft_strjoin_export(char *st1, char *st2);
int		ft_strrcmp(char *st1, char *st2);
char	*malloc_dst(int len);
void	verif_suite3(t_env *env, char *str);
void	verif_suite(t_env *env, char *str);
int	verif_suite_2(t_env *env, char *str);
int		verif(t_env *env, char *str);
void	not_export(t_env *env);
char	check_sep2(char *str);
void	add_pwd(t_env *env, char	*pwd);
char	check_sep_neg(char *str);
/*-------------*/

/*=======EXPENDER=======*/

void	ft_expend(t_stack *stack, t_env *env);
t_env	*list_new(char **matrix, int i, t_env *tmp);
char	**list_to_matrix(t_env *env);
int		verif_char_special(char *str, t_node *next);
int		verif_char_special2(char *str, t_node *next);
int	ft_count_quote(t_node *str, int i, int len);
void	ft_split_cot(t_node *str);
void if_or_not_convert(t_node *str, t_env *env);
int check_if_dollard(char *str);
void convert_dollar(t_node *str, t_env *env);
int check_quote_not_open(t_node *str);

/*======================*/

#endif
