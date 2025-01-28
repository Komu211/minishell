/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:42:59 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/28 18:54:09 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "execution.h"
#include "signal_handler.h"

typedef struct s_heredoc
{
	char *delimiter; // The heredoc delimiter (e.g., "EOF")
	char *temp_file; // Path to temp file that will store content
	struct s_heredoc	*next;
}						t_heredoc;

static void	read_single_heredoc(t_heredoc *current)
{
	int		fd;
	char	*line;
	char	*user_in;

	fd = fdc_open_mode(current->temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			line = readline("heredoc> ");
		else
			line = get_next_line(STDIN_FILENO);
		if (line)
		{
			user_in = gc_strdup(line);
			free(line); // Free readline/get_next_line allocated memory
		}
		else
			user_in = NULL;
		if (!user_in || ft_strcmp(user_in, current->delimiter) == 0)
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

void	read_heredocs(t_heredoc *heredocs)
{
	t_heredoc	*current;
	pid_t		pid;
	int			status;

	current = heredocs;
	while (current)
	{
		pid = fork();
		if (pid == -1)
			return ;
		else if (pid == 0)
		{
			// Child process
			signal(SIGINT, SIG_DFL); // Reset signal handling
			signal(SIGQUIT, SIG_IGN);
			read_single_heredoc(current);
			exit(EXIT_SUCCESS);
		}
		else
		{
			// Parent process
			waitpid(pid, &status, 0);
			if (WIFSIGNALED(status))
			{
				(*get_mini())->exit_status = 128 + WTERMSIG(status);
				return ;
			}
		}
		current = current->next;
	}
}
