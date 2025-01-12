/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_collector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:00:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 14:39:12 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_COLLECTOR_H
# define FD_COLLECTOR_H

# include "error.h"
# include "garbage_collector.h"
# include "libft.h"
# include "utils.h"
# include "wrapper.h"
# include <unistd.h>

typedef struct s_fd
{
	int	fd;
	char *filename; // Name of the file this fd belongs to
}		t_fd;

t_list	**fd_collector(void);
void	fd_collector_add(int fd, char *description);
int		fd_collector_remove(int fd);
void	fd_collector_empty(void);

#endif