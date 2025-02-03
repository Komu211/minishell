/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:34:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 15:39:26 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome(void)
{
	ft_putstr_fd("\033[1;36m", 1);
	ft_putendl_fd("┌──────────────────────────────────────────────────────┐",
		1);
	ft_putendl_fd("│    ____  __ __                  _____ __         ____│",
		1);
	ft_putendl_fd("│   / __ \\/ //_/__  ____ ___  __ / ___// /_  ___  / / /│",
		1);
	ft_putendl_fd("│  / / / / ,< / _ \\/ __ `/ / / / \\__ \\/ __ \\/ _ \\/ / "
		"/ │", 1);
	ft_putendl_fd("│ / /_/ / /| /  __/ /_/ / /_/ / ___/ / / / /  __/ / /  │",
		1);
	ft_putendl_fd("│ \\____/_/ |_\\___/\\__,_/\\__, / /____/_/ /_/\\___/_/_"
		"/   │", 1);
	ft_putendl_fd("│                      /____/                          │",
		1);
	ft_putendl_fd("└──────────────────────────────────────────────────────┘",
		1);
	ft_putstr_fd("\033[0m\n", 1);
}

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
	(*mini)->identifier = generate_unique_identifier();
	if (isatty(STDIN_FILENO))
		print_welcome();
}
