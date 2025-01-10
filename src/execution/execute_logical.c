/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_logical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:20 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_and(t_minishell *mini, t_ast_node *ast)
{
	int	left_status;

	left_status = execute_ast(mini, ast->left);
	if (left_status == 0)
		return (execute_ast(mini, ast->right));
	return (left_status);
}

int	execute_or(t_minishell *mini, t_ast_node *ast)
{
	int	left_status;

	left_status = execute_ast(mini, ast->left);
	if (left_status != 0)
		return (execute_ast(mini, ast->right));
	return (left_status);
}
