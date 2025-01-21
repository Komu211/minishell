/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_in_redirections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:29:23 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 18:21:32 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	handle_input_redirection(t_redirection *redir, t_saved_fds *saved)
{
	int	fd;

	fd = fdc_open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(redir->file, 2);
		ft_putendl_fd(": No such file or directory", 2);
		reset_fds(saved);
		return (1);
	}
	if (fdc_dup2(fd, STDIN_FILENO) == -1)
	{
		fdc_close(fd);
		error_handler("failed to redirect input", 1);
	}
	fdc_close(fd);
	return (0);
}

int	handle_all_inputs(t_redirection *redir, t_saved_fds *saved)
{
	int	ret;

	ret = 0;
	while (redir && !ret)
	{
		if (redir->type == REDIRECT_HERE_DOC)
			ret = handle_here_doc(redir, saved);
		else
			ret = handle_input_redirection(redir, saved);
		redir = redir->next;
	}
	return (ret);
}
