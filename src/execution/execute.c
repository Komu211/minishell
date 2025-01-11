/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:34:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 18:33:21 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_ast(t_minishell *mini, t_ast_node *ast)
{
	t_builtin_type	builtin_type;

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
	else if (is_redirection(ast->type))
		return (execute_redirection(mini, ast));
	return (0);
}
