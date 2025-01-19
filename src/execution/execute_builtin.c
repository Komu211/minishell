/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 15:03:24 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fake_builtin(t_minishell *mini, t_ast_node *ast,
		t_builtin_type builtin_type)
{
	if (builtin_type == BUILTIN_EXIT)
		return (mini->exit_status = 0, 0);
	if (builtin_type == BUILTIN_ECHO)
		return (mini->exit_status = builtin_echo(ast->args), 0);
	if (builtin_type == BUILTIN_CD)
		return (0);
	if (builtin_type == BUILTIN_PWD)
		return (builtin_pwd(mini));
	if (builtin_type == BUILTIN_EXPORT)
		return (0);
	if (builtin_type == BUILTIN_UNSET)
		return (BUILTIN_UNSET);
	if (builtin_type == BUILTIN_EXIT)
		return (mini->exit_status = 0, 0);
	return (0);
}

int	execute_own_builtin(t_minishell *mini, t_ast_node *ast,
		t_builtin_type builtin_type)
{
	if (ast->in_parentheses)
		return (fake_builtin(mini, ast, builtin_type));
	if (builtin_type == BUILTIN_ENV)
		return (builtin_env(mini->env_list));
	else if (builtin_type == BUILTIN_ECHO)
		return (builtin_echo(ast->args));
	else if (builtin_type == BUILTIN_CD)
		return (builtin_cd(mini, ast->args));
	else if (builtin_type == BUILTIN_PWD)
		return (builtin_pwd(mini));
	else if (builtin_type == BUILTIN_EXPORT)
		return (builtin_export(mini, ast->args));
	else if (builtin_type == BUILTIN_UNSET)
		return (builtin_unset(mini, ast));
	else if (builtin_type == BUILTIN_EXIT)
		return (builtin_exit(mini, ast->args), 0);
	(void)ast;
	return (0);
}
