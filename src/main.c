/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:06:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 15:37:19 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_heredocs(t_minishell *mini, t_heredoc **heredocs,
		int *heredoc_counter)
{
	*heredocs = NULL;
	if (mini->ast && collect_heredocs_from_node(mini->ast, heredocs,
			heredoc_counter) && read_heredocs(*heredocs, mini))
	{
		apply_heredocs_to_ast(mini->ast, *heredocs);
		return (1);
	}
	return (0);
}

static void	process_command(t_minishell *mini, char *user_in,
		t_heredoc **heredocs, int *heredoc_counter)
{
	if (*user_in)
	{
		ast_init(&mini->ast, user_in, mini);
		if (handle_heredocs(mini, heredocs, heredoc_counter))
			mini->exit_status = execute_ast(mini, mini->ast);
		mini->ast = ast_empty(mini->ast);
		add_history(user_in);
		gc_free(user_in);
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
		gc_free(prompt);
		fd_collector_empty();
		empty_heredoc(&heredocs);
	}
	cleanup_main(mini);
	return (mini->exit_status);
}
