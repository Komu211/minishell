/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:34:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 15:56:40 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_ast(t_minishell *mini, t_ast_node *ast)
{
	t_builtin_type	builtin_type;

	// int				fd[2];
	// fd[0] = STDIN_FILENO;
	// fd[1] = STDOUT_FILENO;
	// if (ast->redirections_in || ast->redirections_out)
	// 	handle_redirections(ast, fd);
	if (ast->type == TOKEN_COMMAND)
	{
		builtin_type = is_own_builtin(ast->args[0], ast->args);
		if (builtin_type != BUILTIN_NONE)
			return (execute_own_builtin(mini, ast, builtin_type));
		else
			return (execute_external_command(mini, ast));
	}
	else if (ast->type == TOKEN_PIPE)
		return (execute_pipe(mini, ast));
	else if (ast->type == TOKEN_AND)
		return (execute_and(mini, ast));
	else if (ast->type == TOKEN_OR)
		return (execute_or(mini, ast));
	// redirection_reset(fd);
	return (0);
}
