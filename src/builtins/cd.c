/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:57:52 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/18 12:06:53 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"
#include <unistd.h>

int	builtin_cd(t_minishell *minishell, char **args)
{
	char	*path;

	(void)minishell;
	if (!args[1])
		path = getenv("HOME");
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
