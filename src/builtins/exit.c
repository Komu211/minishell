/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:35:44 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/17 01:24:54 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"

int	builtin_exit(t_minishell *minishell)
{
	(void)minishell;
	cleanup_main(minishell);
	exit(0);
}
