/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:27 by najeuneh          #+#    #+#             */
/*   Updated: 2024/08/28 15:10:30 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <termios.h>
#include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_printf.h"
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_sign
{
	int g_control;
	char *tmp;
}				t_sign;

int	g_exit_code;

/* lexer */

int		heredoc(t_node *node);
char	check_sep(char c, char *charset);
void	free_stack(t_stack *stack);
void	printf_node(t_stack *stack);
void	lexer(t_stack *stack, char *line, char **env, int start, t_env *envp);
int		lexer_suite(t_stack *stack, char *line, int start, int i);
int		lexer_suite2(t_stack *stack, char *line, int start, int i);

/*-------*/

/* parser */

void	ft_parser(t_stack *stack, t_env *env);
int		ft_checkpath(char **str);
char	*ft_path(char *line, t_env *lst_env);
char	*ft_path2(char **str, char *str2);
t_node	*ft_flagcheck(t_node *node);
void	ft_free_all(char **str);
void	ft_bultincheck(t_node *node);
void	ft_parser2(t_stack *stack, t_env *list_env);
void	ft_finish_node(t_stack *stack, char *in, char *out, int i);
void	ft_suite_node(t_stack *stack, char *in, char *out, int i);
void	ft_clear_all(t_stack *stack);
void	ft_checkflag0(t_stack *stack, int i);
void	ft_checkcmd(t_stack *stack);

/*-------*/

/* exec */

int		ft_countcmd(t_stack *stack);
int		exec(t_stack *stack, t_env *envp);
void	ft_check_fd(t_node *node);
int		multi_cmd(t_stack *stack, t_env *env);
void	ft_use_bultin(t_node *node, t_env *env);
int		simple_cmd(t_node *node,int in_pipe, int out_pipe, t_env *env);


/*-------*/

/*signaux*/

void	ft_control();
void	sig_for_ctrl_c(int signal);
void	sig_for_ctrl_back_slash(int signal);
void	rl_replace_line(const char *text, int clear_undo);

/*-------*/

/*=======BULTINS=======*/

void	ft_echo(t_node *node);
void 	ft_cd(t_env *env, t_node *node);
void	ft_pwd(void);
void    ft_exit(char **str);
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
int	isaldigit(int c);
int	verif_not_aldigit(char *str);
void	ft_export_last(t_env *env, char *node);
char	*ft_strjoin_export(char *st1, char *st2);
/*-------------*/

/*======================*/


/*=======EXPENDER=======*/

void	ft_expend(t_stack *stack, t_env *env);
void expend_verif(t_env *env, int count, t_node	*str, char *first_sep);
void	expend_if_dollard(t_env *env, t_node *str, char *first_sep, int count);
void	expend_ifnot_dollard(t_env *env, t_node *str);

char	*ft_strjoin_expend(char *st1, char *st2);
char	*ft_strcpy3(char *str);
char	*ft_strrev(char *str);
int		count_guillmet(char *str, int i, int len);
int		last_compare(char *sep);

t_env	*list_new(char **matrix);

int sort_single_quote(char **dest, char *str, int *i, int *first);
int sort_double_quote(char **dest, char *str, int *i, int *first);
char *return_for_sort(int result, char *dest);
char	*check_sort_guillmet(char *str, int i, int first, int result);

char  *check_dollar(char *str, t_env *env, char *first_sep, int i);
char *return_env_if_dollar(char *str2, char *str, char *sep, int i);
char *check_dollar_interrogation(char *str);
char *check_first_sep(char *str);
int verif_char_special(char *str);

/*======================*/

#endif
