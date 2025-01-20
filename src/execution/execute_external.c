/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 15:18:20 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "minishell.h"

static int	command_not_found(t_minishell *mini, t_ast_node *ast)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(ast->args[0], 2);
	ft_putendl_fd(": command not found", 2);
	mini->exit_status = 127;
	return (127);
}

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

int	execute_external_command(t_minishell *mini, t_ast_node *ast)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	if (ast->args[0] == NULL)
		return (mini->exit_status = 0);
	cmd_path = get_command_path(ast->args[0], mini->env_list);
	if (!cmd_path || ast->args[0][0] == '\0')
		return (command_not_found(mini, ast));
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(cmd_path, ast->args, env_ll_to_array(mini->env_list));
		perror(ast->args[0]);
		mini->exit_status = 126;
		cleanup_main(mini);
	}
	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno != EINTR)
		{
			perror("waitpid");
			return (mini->exit_status = 1);
		}
	}
	if (WIFSIGNALED(status))
	{
		mini->exit_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
	}
	else
		mini->exit_status = WEXITSTATUS(status);
	return (mini->exit_status);
}
