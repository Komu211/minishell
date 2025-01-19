/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 16:23:21 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_external_command(t_minishell *mini, t_ast_node *ast)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	cmd_path = get_command_path(ast->args[0], mini->env_list);
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(ast->args[0], 2);
		ft_putendl_fd(": command not found", 2);
		return (127);
	}
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		execve(cmd_path, ast->args, mini->env_list_orig);
		perror(ast->args[0]);
		exit(126);
	}
	waitpid(pid, &status, 0);
	mini->exit_status = WEXITSTATUS(status);
	return (mini->exit_status);
}
