/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:42:59 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/29 18:55:36 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"


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
			free(line);
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

	current = heredocs;
	while (current)
	{
		printf("Processing heredoc with delimiter: %s\n", current->delimiter);
		read_single_heredoc(current);
		current = current->next;
	}
	printf("Finished reading heredocs\n");
}
