/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:15:29 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/21 11:03:38 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	handle_here_doc(t_redirection *redir, t_saved_fds *saved)
{
	pid_t	pid;
	int		pipefd[2];
	char	*line;
	char	*user_in;
	int		fd;

	(void)saved;
	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		// Child process
		if (isatty(STDIN_FILENO))
		{
			// Interactive mode, read from /dev/tty
			fd = open("/dev/tty", O_RDONLY);
			if (fd == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			// Non-interactive mode, read from standard input
			fd = STDIN_FILENO;
		}
		close(pipefd[0]); // Close unused read end of the pipe
		while (1)
		{
			if (isatty(fd))
				line = readline("> ");
			else
				line = get_next_line(fd);
			if (line)
			{
				user_in = ft_strtrim(line, "\n");
				free(line);
			}
			else
				user_in = NULL;
			if (!user_in || ft_strcmp(user_in, redir->file) == 0)
			{
				free(user_in);
				break ;
			}
			write(pipefd[1], user_in, ft_strlen(user_in));
			write(pipefd[1], "\n", 1);
			free(user_in);
		}
		if (fd != STDIN_FILENO)
			close(fd);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	return (EXIT_SUCCESS);
}
