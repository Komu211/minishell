/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:09:36 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 17:57:37 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "ast.h"
# include "builtins.h"
# include "enums.h"
# include "env.h"
# include <sys/wait.h>
# include <unistd.h>

int				execute_ast(t_minishell *mini, t_ast_node *ast);
int				execute_own_builtin(t_minishell *mini, t_ast_node *ast,
					t_builtin_type builtin_type);
int				execute_external_command(t_minishell *mini, t_ast_node *ast);
int				execute_pipe(t_minishell *mini, t_ast_node *ast);
int				execute_and(t_minishell *mini, t_ast_node *ast);
int				execute_or(t_minishell *mini, t_ast_node *ast);
t_builtin_type	is_own_builtin(char *command, char **args);
void			test_execute_command(t_minishell *mini, t_ast_node *ast);
char			*get_command_path(char *command, t_list *env_list);
#endif
