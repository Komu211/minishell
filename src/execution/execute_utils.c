/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:36:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:21 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_own_builtin(char *command, char **args)
{
	(void)args;
	(void)command;
	return (0);
}

// char	*find_command_path(char *command, char **env_path)
// {
// 	char	*path;
// 	char	*full_path;
// 	char	**paths;
// 	int		i;

// 	if (access(command, X_OK) == 0)
// 		return (ft_strdup(command));
// 	if (!env_path || !*env_path)
// 		return (NULL);
// 	paths = ft_split(*env_path, ':');
// 	if (!paths)
// 		return (NULL);
// 	i = 0;
// 	while (paths[i])
// 	{
// 		path = ft_strjoin(paths[i], "/");
// 		full_path = ft_strjoin(path, command);
// 		free(path);
// 		if (access(full_path, X_OK) == 0)
// 			return (full_path);
// 		free(full_path);
// 		i++;
// 	}
// 	ft_free_array(paths);
// 	return (NULL);
// }
