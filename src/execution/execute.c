/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:34:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:21 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_ast(t_minishell *mini, t_ast_node *ast)
{
	if (ast->type == TOKEN_COMMAND)
		if (is_own_builtin(ast->args[0], ast->args))
			return (execute_own_builtin(mini, ast));
		else
			return (execute_external_command(mini, ast));
	else if (ast->type == TOKEN_PIPE)
		return (execute_pipe(mini, ast));
	else if (ast->type == TOKEN_AND)
		return (execute_and(mini, ast));
	else if (ast->type == TOKEN_OR)
		return (execute_or(mini, ast));
	return (0);
}
