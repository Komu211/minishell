/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:57:52 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 15:23:03 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"
#include <unistd.h>

#define PATH_MAX 4096

static int	update_pwd(t_minishell *minishell, char *cwd)
{
	env_set(minishell, "OLD_PWD", minishell->pwd);
	minishell->pwd = gc_strdup(cwd);
	env_set(minishell, "PWD", minishell->pwd);
	return (0);
}

static int	not_set(char *var, t_minishell *minishell)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(var, 2);
	ft_putendl_fd(" not set", 2);
	minishell->exit_status = 1;
	return (1);
}

int	builtin_cd(t_minishell *minishell, char **args)
{
	const char	*path;
	char		cwd[PATH_MAX];

	if (!args[1] || (args[1][0] == '-' && args[1][1] == '-' && !args[1][2]))
	{
		path = get_env_value("HOME", minishell->env_list);
		if (!path)
			return (not_set("HOME", minishell));
	}
	else if (args[1][0] == '-' && !args[1][1])
	{
		path = get_env_value("OLD_PWD", minishell->env_list);
		if (!path)
			return (not_set("OLD_PWD", minishell));
		printf("%s\n", path);
	}
	else
		path = args[1];
	if (chdir(path) == -1 || getcwd(cwd, sizeof(cwd)) == NULL)
		return (perror("cd"), 1);
	return (update_pwd(minishell, cwd));
}
