/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:36:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 14:39:50 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_builtin_type	is_own_builtin(char *command, char **args)
{
	(void)args;
	if (ft_strncmp(command, "cd", 2) == 0)
		return (BUILTIN_CD);
	if (ft_strncmp(command, "echo", 4) == 0)
		return (BUILTIN_ECHO);
	if (ft_strncmp(command, "env", 3) == 0)
		return (BUILTIN_ENV);
	if (ft_strncmp(command, "exit", 4) == 0)
		return (BUILTIN_EXIT);
	if (ft_strncmp(command, "export", 6) == 0)
		return (BUILTIN_EXPORT);
	if (ft_strncmp(command, "pwd", 3) == 0)
		return (BUILTIN_PWD);
	if (ft_strncmp(command, "unset", 5) == 0)
		return (BUILTIN_UNSET);
	return (BUILTIN_NONE);
}

char	*get_command_path(char *command, t_list *env_list)
{
	char		**path;
	const char	*env_path;
	char		*command_path;
	int			i;
	char		*tmp;

	if (access(command, F_OK) == 0)
		return (gc_strdup(command));
	env_path = get_env_value("PATH", env_list);
	if (!env_path)
		return (NULL);
	path = gc_split_at(env_path, ':');
	i = 0;
	while (path[i])
	{
		tmp = gc_strjoin(path[i], "/");
		command_path = gc_strjoin(tmp, command);
		gc_free(tmp);
		if (access(command_path, F_OK) == 0)
			return (gc_split_free(&path), command_path);
		gc_free(command_path);
		i++;
	}
	gc_split_free(&path);
	return (NULL);
}
