/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:10:46 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:22 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	test_execute_command(t_minishell *mini, t_ast_node *ast)
{
	pid_t	pid;

	(void)mini;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
		execve("echo", ast->args, NULL);
	else
		waitpid(pid, NULL, 0);
}
