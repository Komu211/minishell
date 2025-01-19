/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:32:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 18:03:02 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

static int	is_n_flag(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i + 1] && arg[i + 1][0] == '-')
	{
		j = 1;
		while (arg[i + 1][j] == 'n')
			j++;
		if (arg[i + 1][j] != '\0')
			break ;
		if (j == 1)
			break ;
		i++;
	}
	return (i);
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
