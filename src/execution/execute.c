/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:34:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 17:24:14 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_ast(t_minishell *mini, t_ast_node *ast)
{
	t_builtin_type	builtin_type;
	t_saved_fds		saved;
	int				ret;

	if (!ast)
		return (0);
	handle_redirections(ast, &saved);
	if (ast->type == TOKEN_COMMAND)
	{
		builtin_type = is_own_builtin(ast->args[0], ast->args);
		if (builtin_type != BUILTIN_NONE)
			ret = execute_own_builtin(mini, ast, builtin_type);
		else
			ret = execute_external_command(mini, ast);
	}
	else if (ast->type == TOKEN_PIPE)
		ret = execute_pipe(mini, ast);
	else if (ast->type == TOKEN_AND)
		ret = execute_and(mini, ast);
	else if (ast->type == TOKEN_OR)
		ret = execute_or(mini, ast);
	else
		ret = 0;
	if (ast->redirections_in || ast->redirections_out)
		reset_fds(&saved);
	return (ret);
}
