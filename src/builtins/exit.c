/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:35:44 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 10:30:16 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"

static int	is_numeric(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	builtin_exit(t_minishell *minishell, char **args)
{
	if (args[1] && !is_numeric(args[1]))
	{
		minishell->exit_status = 255;
		cleanup_main(minishell);
		exit(255);
	}
	minishell->exit_status = ft_atoi(args[1]);
	cleanup_main(minishell);
}

