/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:54:35 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 16:53:53 by kmuhlbau         ###   ########.fr       */
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
		ft_putendl_fd("failed to save file descriptors", 2);
		reset_fds(saved);
		exit(1);
	}
}

void	handle_redirections(t_ast_node *ast, t_saved_fds *saved)
{
	if (!ast || (!ast->redirections_in && !ast->redirections_out))
		return ;
	init_and_save_fds(saved);
	handle_all_inputs(ast->redirections_in, saved);
	handle_all_outputs(ast->redirections_out, saved);
}

void	reset_fds(t_saved_fds *saved)
{
	if (saved->o_stdin != -1)
	{
		if (fdc_dup2(saved->o_stdin, STDIN_FILENO) == -1)
			ft_putendl_fd("failed to restore stdin", 2);
		fdc_close(saved->o_stdin);
		saved->o_stdin = -1;
	}
	if (saved->o_stdout != -1)
	{
		if (fdc_dup2(saved->o_stdout, STDOUT_FILENO) == -1)
			ft_putendl_fd("failed to restore stdout", 2);
		fdc_close(saved->o_stdout);
		saved->o_stdout = -1;
	}
}
