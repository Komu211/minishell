/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:32:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/18 11:42:39 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

static int	is_n_flag(char **arg)
{
	if (!arg[1] || arg[1][0] != '-')
		return (0);
	if (arg[1][1] != 'n')
		return (0);
	return (1);
}

int	builtin_echo(char **args)
{
	int	i;
	int	n_flag;

	if (!args || !args[1])
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	n_flag = is_n_flag(args);
	i = 1;
	while (args[i + n_flag])
	{
		printf("%s", args[i + n_flag]);
		if (args[i + n_flag + 1])
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	return (0);
}
