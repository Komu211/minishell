/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:34:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 13:30:04 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_init(char **envp, t_minishell **mini, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	*mini = gc_calloc(1, sizeof(t_minishell));
	*get_mini() = *mini;
	(*mini)->pwd = gc_getcwd(NULL);
	if (!(*mini)->pwd)
		error_handler("getcwd failed", 1);
	(*mini)->hist_file = gc_strjoin((*mini)->pwd, "/.minishell_history");
	if (!(*mini)->hist_file)
		error_handler("ft_strjoin failed", 1);
	env_init(*mini, envp);
	(*mini)->error = 0;
	(*mini)->exit_status = 0;
	(*mini)->old_pwd = NULL;
	(*mini)->identifier = generate_unique_identifier();
}
