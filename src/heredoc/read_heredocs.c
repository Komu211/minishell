/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:42:59 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 17:39:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	read_single_heredoc(t_heredoc *current, t_minishell *mini)
{
	int		fd;
	char	*user_in;

	fd = fdc_open_mode(current->temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	while (!mini->heredoc_interrupted)
	{
		user_in = get_user_input("heredoc> ");
		if (!user_in)
			break ;
		garbage_collector_add(user_in);
		if (ft_strcmp(user_in, current->delimiter) == 0)
		{
			gc_free(user_in);
			break ;
		}
		write(fd, user_in, ft_strlen(user_in));
		write(fd, "\n", 1);
		gc_free(user_in);
	}
	fdc_close(fd);
}

int	read_heredocs(t_heredoc *heredocs, t_minishell *mini)
{
	t_heredoc	*current;

	if (!heredocs)
		return (1);
	current = heredocs;
	mini->heredoc_interrupted = 0;
	setup_parent_signals();
	setup_heredoc_handler(mini);
	while (current)
	{
		read_single_heredoc(current, mini);
		if (mini->heredoc_interrupted)
			break ;
		current = current->next;
	}
	restore_signals(mini);
	mini->exit_status = mini->heredoc_interrupted;
	return (!mini->heredoc_interrupted);
}
