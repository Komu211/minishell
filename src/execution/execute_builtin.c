/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 17:58:06 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_own_builtin(t_minishell *mini, t_ast_node *ast,
		t_builtin_type builtin_type)
{
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
