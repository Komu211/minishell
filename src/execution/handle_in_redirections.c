/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_in_redirections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:29:23 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 12:17:18 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	handle_input_redirection(t_redirection *redir, t_saved_fds *saved)
{
	int	fd;

	fd = fdc_open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(redir->file, 2);
		ft_putendl_fd(": No such file or directory", 2);
		reset_fds(saved);
		exit(1);
	}
	if (fdc_dup2(fd, STDIN_FILENO) == -1)
	{
		fdc_close(fd);
		reset_fds(saved);
		exit(1);
	}
	fdc_close(fd);
}

void	handle_all_inputs(t_redirection *redir, t_saved_fds *saved)
{
	while (redir)
	{
		if (redir->type != REDIRECT_HERE_DOC)
			handle_input_redirection(redir, saved);
		redir = redir->next;
	}
}
