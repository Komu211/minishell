/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 14:20:18 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "minishell.h"

static char	**env_ll_to_array(t_list *env_list)
{
	char	**env_array;
	t_env	*env;
	int		i;
	char	*tmp;

	env_array = gc_malloc(sizeof(char *) * (ft_lstsize(env_list) + 1));
	if (!env_array)
		return (NULL);
	i = 0;
	while (env_list)
	{
		env = (t_env *)env_list->content;
		if (env->value)
		{
			tmp = gc_strjoin(env->key, "=");
			env_array[i++] = gc_strjoin(tmp, env->value);
			gc_free(tmp);
		}
		else
			env_array[i++] = gc_strdup(env->key);
		env_list = env_list->next;
	}
	env_array[i] = NULL;
	return (env_array);
}

static int	handle_child_exit(t_minishell *mini, int status)
{
	if (WIFSIGNALED(status))
	{
		mini->exit_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGINT)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
		mini->exit_status = WEXITSTATUS(status);
	return (mini->exit_status);
}

static int	execute_child_process(t_minishell *mini, t_ast_node *ast,
		char *cmd_path)
{
	pid_t	pid;
	int		status;

	setup_parent_signals();
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		setup_child_signals();
		execve(cmd_path, ast->args, env_ll_to_array(mini->env_list));
		perror(ast->args[0]);
		mini->exit_status = 126;
		cleanup_main(mini);
	}
	waitpid(pid, &status, 0);
	restore_signals(mini);
	return (handle_child_exit(mini, status));
}

int	execute_external_command(t_minishell *mini, t_ast_node *ast)
{
	char	*cmd_path;

	if (ast->args[0] == NULL)
		return (mini->exit_status = 0);
	cmd_path = get_command_path(ast->args[0], mini->env_list);
	if (!cmd_path || ast->args[0][0] == '\0')
		return (command_not_found(mini, ast));
	return (execute_child_process(mini, ast, cmd_path));
}
