/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:00:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 14:17:45 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_collector.h"

void	fd_collector_add(int fd, char *filename)
{
	t_fd	*fd_info;
	t_list	*new;

	fd_info = gc_malloc(sizeof(t_fd));
	if (!fd_info)
		error_handler("Failed to allocate memory for fd collector", 1);
	fd_info->fd = fd;
	if (filename)
		fd_info->filename = gc_strdup(filename);
	else
		fd_info->filename = NULL;
	new = gc_lstnew(fd_info);
	if (!new)
		error_handler("Failed to allocate memory for fd collector node", 1);
	ft_lstadd_front(fd_collector(), new);
}
