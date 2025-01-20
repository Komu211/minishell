/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:36:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 15:29:47 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_builtin_type	is_own_builtin(char *command, char **args)
{
	(void)args;
	if (command == NULL)
		return (BUILTIN_NONE);
	if (ft_strncmp(command, "cd", 3) == 0)
		return (BUILTIN_CD);
	if (ft_strncmp(command, "echo", 5) == 0)
		return (BUILTIN_ECHO);
	if (ft_strncmp(command, "env", 4) == 0)
		return (BUILTIN_ENV);
	if (ft_strncmp(command, "exit", 5) == 0)
		return (BUILTIN_EXIT);
	if (ft_strncmp(command, "export", 7) == 0)
		return (BUILTIN_EXPORT);
	if (ft_strncmp(command, "pwd", 4) == 0)
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

	if (access(command, F_OK) == 0 && ft_strchr(command, '/'))
		return (gc_strdup(command));
	else if (ft_strchr(command, '/'))
		return (NULL);
	env_path = get_env_value("PATH", env_list);
	if (!env_path)
		return (NULL);
	path = gc_split_at(env_path, ':');
	i = -1;
	while (path[++i])
	{
		tmp = gc_strjoin(path[i], "/");
		command_path = gc_strjoin(tmp, command);
		gc_free(tmp);
		if (access(command_path, F_OK) == 0)
			return (gc_split_free(&path), command_path);
		gc_free(command_path);
	}
	return (gc_split_free(&path), NULL);
}
