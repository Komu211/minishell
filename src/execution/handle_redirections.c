/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:54:35 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/21 11:19:40 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	init_and_save_fds(t_saved_fds *saved)
{
	saved->o_stdin = -1;
	saved->o_stdout = -1;
	saved->o_stdin = fdc_dup(STDIN_FILENO);
	saved->o_stdout = fdc_dup(STDOUT_FILENO);
	if (saved->o_stdin == -1 || saved->o_stdout == -1)
	{
		reset_fds(saved);
		error_handler("failed to save file descriptors", 1);
	}
}

int	handle_redirections(t_ast_node *ast, t_saved_fds *saved)
{
	if (!ast->redirections_in && !ast->redirections_out)
		return (0);
	init_and_save_fds(saved);
	if (handle_all_inputs(ast->redirections_in, saved))
		return (1);
	if (handle_all_outputs(ast->redirections_out, saved))
		return (1);
	return (0);
}

void	reset_fds(t_saved_fds *saved)
{
	if (saved->o_stdin != -1)
	{
		if (fdc_dup2(saved->o_stdin, STDIN_FILENO) == -1)
			error_handler("failed to restore stdin", 2);
		fdc_close(saved->o_stdin);
		saved->o_stdin = -1;
	}
	if (saved->o_stdout != -1)
	{
		if (fdc_dup2(saved->o_stdout, STDOUT_FILENO) == -1)
			error_handler("failed to restore stdout", 2);
		fdc_close(saved->o_stdout);
		saved->o_stdout = -1;
	}
}
