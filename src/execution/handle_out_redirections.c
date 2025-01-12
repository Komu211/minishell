/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_out_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:30:41 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 16:37:29 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_mode(t_redirection_type type)
{
	if (type == REDIRECT_OUT_APPEND)
		return (O_APPEND);
	if (type == REDIRECT_OUT)
		return (O_TRUNC);
	if (type == REDIRECT_IN)
		return (O_RDONLY);
	if (type == REDIRECT_HERE_DOC)
		return (O_RDONLY);
	return (-1);
}

static void	handle_output_redirection(t_redirection *redir, t_saved_fds *saved)
{
	int	fd;
	int	mode;

	mode = get_mode(redir->type);
	fd = fdc_open_mode(redir->file, O_WRONLY | O_CREAT | mode, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(redir->file, 2);
		ft_putendl_fd(": Permission denied", 2);
		reset_fds(saved);
		exit(1);
	}
	if (fdc_dup2(fd, STDOUT_FILENO) == -1)
	{
		fdc_close(fd);
		reset_fds(saved);
		exit(1);
	}
	fdc_close(fd);
}

void	handle_all_outputs(t_redirection *redir, t_saved_fds *saved)
{
	while (redir)
	{
		handle_output_redirection(redir, saved);
		redir = redir->next;
	}
}
