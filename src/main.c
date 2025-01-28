/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:06:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/28 18:58:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_heredoc
{
	char *delimiter; // The heredoc delimiter (e.g., "EOF")
	char *temp_file; // Path to temp file that will store content
	struct s_heredoc	*next;
}						t_heredoc;
void					collect_heredocs_from_node(t_ast_node *node,
							t_heredoc **heredocs, int *counter);
void					read_heredocs(t_heredoc *heredocs);

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
					"/ │",
					1);
	ft_putendl_fd("│ / /_/ / /| /  __/ /_/ / /_/ / ___/ / / / /  __/ / /  │",
		1);
	ft_putendl_fd("│ \\____/_/ |_\\___/\\__,_/\\__, / /____/_/ /_/\\___/_/_"
					"/   │",
					1);
	ft_putendl_fd("│                      /____/                          │",
		1);
	ft_putendl_fd("└──────────────────────────────────────────────────────┘",
		1);
	ft_putstr_fd("\033[0m\n", 1);
}

void	mini_init(char **envp, t_minishell **mini)
{
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
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	char		*user_in;
	char		*prompt;
	char		*line;
	t_heredoc	*heredocs;
	int			heredoc_counter;

	(void)argc;
	(void)argv;
	mini_init(envp, &mini);
	signal_setup(mini);
	heredoc_counter = 0;
	heredocs = NULL;
	while (42)
	{
		prompt = gc_strjoin(mini->pwd, " > ");
		if (isatty(fileno(stdin)))
			user_in = readline(prompt);
		else
		{
			line = get_next_line(fileno(stdin));
			if (line)
			{
				user_in = ft_strtrim(line, "\n");
				free(line);
			}
			else
				user_in = NULL;
		}
		if (!user_in)
			break ;
		garbage_collector_add(user_in);
		if (*user_in) // Only process non-empty input
		{
			ast_init(&mini->ast, user_in, mini);
			if (mini->ast)
			{
				// printf("\nCommand entered: %s\n", user_in);
				// debug_ast(mini.ast);
				collect_heredocs_from_node(mini->ast, &heredocs,
					&heredoc_counter);
				if (heredocs)
				{
					read_heredocs(heredocs);
					//append_heredocs_to_ast(mini->ast, heredocs);
				}
				mini->exit_status = execute_ast(mini, mini->ast);
				// Free previous AST before next iteration
				mini->ast = ast_empty(mini->ast);
			}
			add_history(user_in); // Add command to readline history
		}
		gc_free(user_in);
		gc_free(prompt);
	}
	cleanup_main(mini);
	return (mini->exit_status);
}
