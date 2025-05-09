/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 15:33:13 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static pid_t	execute_left(t_minishell *mini, t_ast_node *ast, int pipefd[2])
{
	pid_t	pid1;
	int		ret;

	pid1 = fork();
	if (pid1 == -1)
		return (-1);
	else if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		ret = execute_ast(mini, ast->left);
		garbage_collector_empty();
		exit(ret);
	}
	return (pid1);
}

static pid_t	execute_right(t_minishell *mini, t_ast_node *ast, int pipefd[2])
{
	pid_t	pid2;
	int		ret;

	pid2 = fork();
	if (pid2 == -1)
		return (-1);
	else if (pid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		ret = execute_ast(mini, ast->right);
		garbage_collector_empty();
		exit(ret);
	}
	return (pid2);
}

int	execute_pipe(t_minishell *mini, t_ast_node *ast)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(pipefd) == -1)
		return (1);
	pid1 = execute_left(mini, ast, pipefd);
	if (pid1 == -1)
		return (1);
	pid2 = execute_right(mini, ast, pipefd);
	if (pid2 == -1)
		return (1);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	status1 = WEXITSTATUS(status1);
	status2 = WEXITSTATUS(status2);
	mini->exit_status = status2;
	return (mini->exit_status);
}
