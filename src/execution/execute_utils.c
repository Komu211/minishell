/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:36:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 17:18:00 by kmuhlbau         ###   ########.fr       */
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

static char	*build_path(const char *command, const char *path)
{
	char	*result;

	result = gc_calloc(ft_strlen(path) + ft_strlen(command) + 2, sizeof(char));
	ft_memcpy(result, path, ft_strlen(path));
	ft_memcpy(result + ft_strlen(path), "/", 1);
	ft_memcpy(result + ft_strlen(path) + 1, command, ft_strlen(command));
	return (result);
}

char	*get_command_path(char *command, t_list *env_list)
{
	char		**path;
	const char	*env_path;
	char		*command_path;
	int			i;
	
	if (access(command, F_OK) == 0 && ft_strchr(command, '/'))
		return (gc_strdup(command));
	else if (ft_strchr(command, '/'))
		return (NULL);
	env_path = get_env_value("PATH", env_list);
	if (!env_path)
		return (build_path(command, get_env_value("PWD", env_list)));
	path = gc_split_at(env_path, ':');
	i = -1;
	while (path[++i])
	{
		command_path = build_path(command, path[i]);
		if (access(command_path, F_OK) == 0)
			return (gc_split_free(&path), command_path);
		gc_free(command_path);
	}
	return (gc_split_free(&path), NULL);
}
