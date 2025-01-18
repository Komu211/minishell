/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:57:52 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/18 13:28:19 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"
#include <unistd.h>

#define PATH_MAX 4096

int	builtin_cd(t_minishell *minishell, char **args)
{
	char	*path;
	char	cwd[PATH_MAX];

	if (!args[1])
		path = getenv("HOME");
	else if (args[1][0] == '-')
		path = minishell->old_pwd;
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("cd");
		return (1);
	}
	if (minishell->old_pwd)
		gc_free(minishell->old_pwd);
	minishell->old_pwd = minishell->pwd;
	minishell->pwd = gc_strdup(cwd);
	return (0);
}
