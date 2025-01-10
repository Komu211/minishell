/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:09:36 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:12 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "ast.h"
# include <sys/wait.h>
# include <unistd.h>

int		execute_ast(t_minishell *mini, t_ast_node *ast);
int		execute_own_builtin(t_minishell *mini, t_ast_node *ast);
int		execute_external_command(t_minishell *mini, t_ast_node *ast);
int		execute_pipe(t_minishell *mini, t_ast_node *ast);
int		execute_and(t_minishell *mini, t_ast_node *ast);
int		execute_or(t_minishell *mini, t_ast_node *ast);
int		is_own_builtin(char *command, char **args);
void	test_execute_command(t_minishell *mini, t_ast_node *ast);

#endif