/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:06:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 17:34:29 by kmuhlbau         ###   ########.fr       */
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

static void	handle_heredocs(t_minishell *mini, t_heredoc **heredocs,
		int *heredoc_counter)
{
	*heredocs = NULL;
	if (mini->ast && collect_heredocs_from_node(mini->ast, heredocs,
			heredoc_counter) && read_heredocs(*heredocs, mini))
	{
		apply_heredocs_to_ast(mini->ast, *heredocs);
	}
}

static char	*get_user_input(char *prompt)
{
	char	*user_in;
	char	*line;

	if (isatty(STDIN_FILENO))
		user_in = readline(prompt);
	else
	{
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			user_in = ft_strtrim(line, "\n");
			free(line);
		}
		else
			user_in = NULL;
	}
	return (user_in);
}

static void	process_command(t_minishell *mini, char *user_in,
		t_heredoc **heredocs, int *heredoc_counter)
{
	if (*user_in)
	{
		ast_init(&mini->ast, user_in, mini);
		handle_heredocs(mini, heredocs, heredoc_counter);
		if (mini->ast)
		{
			mini->exit_status = execute_ast(mini, mini->ast);
			mini->ast = ast_empty(mini->ast);
		}
		add_history(user_in);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	char		*user_in;
	char		*prompt;
	t_heredoc	*heredocs;
	int			heredoc_counter;

	mini_init(envp, &mini, argc, argv);
	signal_setup(mini);
	heredoc_counter = 0;
	heredocs = NULL;
	while (42)
	{
		prompt = gc_strjoin(mini->pwd, " > ");
		user_in = get_user_input(prompt);
		if (!user_in)
			break ;
		garbage_collector_add(user_in);
		process_command(mini, user_in, &heredocs, &heredoc_counter);
		gc_free(user_in);
		gc_free(prompt);
		fd_collector_empty();
		empty_heredoc(&heredocs);
	}
	cleanup_main(mini);
	return (mini->exit_status);
}
