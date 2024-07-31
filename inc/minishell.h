/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:36:27 by najeuneh          #+#    #+#             */
/*   Updated: 2024/07/30 19:00:11 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include "libft.h"
# include "pipex.h"
# include <readline/history.h>
# include <readline/readline.h>

void	free_stack(t_stack *stack);
void	printf_node(t_stack *stack);
void	lexer(t_stack *stack, char *line, int start);
int		lexer_suite(t_stack *stack, char *line, int start, int i);
int		lexer_suite2(t_stack *stack, char *line, int start, int i);
char	**ft_split_multi(char *str, char *charset);

#endif
