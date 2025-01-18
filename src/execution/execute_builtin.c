/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/17 01:49:26 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fake_builtin(t_minishell *mini, t_ast_node *ast,
		t_builtin_type builtin_type)
{
	if (builtin_type == BUILTIN_EXIT)
		return (0);
	//	if (builtin_type == BUILTIN_ECHO)
	//		return (builtin_echo(ast->args));
	//	if (builtin_type == BUILTIN_CD)
	//		return (0);
	//	if (builtin_type == BUILTIN_PWD)
	//		return (builtin_pwd());
	//	if (builtin_type == BUILTIN_EXPORT)
	//		return (0);
	//	if (builtin_type == BUILTIN_UNSET)
	//		return (0);
	//	if (builtin_type == BUILTIN_EXIT)
	//		return (0);

	(void)builtin_type;
	(void)ast;
	(void)mini;
	return (0);
}

int	execute_own_builtin(t_minishell *mini, t_ast_node *ast,
		t_builtin_type builtin_type)
{
	if (ast->in_parentheses)
		return (fake_builtin(mini, ast, builtin_type));
	if (builtin_type == BUILTIN_ENV)
		return (builtin_env(mini->env_list));
	// else if (builtin_type == BUILTIN_ECHO)
	// 	return (builtin_echo(ast->args));
	// else if (builtin_type == BUILTIN_CD)
	// 	return (builtin_cd(ast->args, mini->env_list));
	// else if (builtin_type == BUILTIN_PWD)
	// 	return (builtin_pwd());
	// else if (builtin_type == BUILTIN_EXPORT)
	// 	return (builtin_export(ast->args, &mini->env_list));
	// else if (builtin_type == BUILTIN_UNSET)
	// 	return (builtin_unset(ast->args, &mini->env_list));
	// else if (builtin_type == BUILTIN_EXIT)
	// 	return (builtin_exit(mini, ast->args));
	(void)ast;
	return (0);
}
