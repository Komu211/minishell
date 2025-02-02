/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:00:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/02 10:45:05 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_collector.h"

static void	fd_destroy(void *content)
{
	t_fd	*fd_info;

	fd_info = (t_fd *)content;
	if (fd_info->fd > 2)
		close(fd_info->fd);
	if (fd_info->filename)
		gc_free(fd_info->filename);
	gc_free(fd_info);
}

void	fd_collector_empty(void)
{
	t_list	**holder;

	holder = fd_collector();
	gc_lstclear(holder, fd_destroy);
}
