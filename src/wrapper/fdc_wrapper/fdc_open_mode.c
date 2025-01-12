/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdc_open_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:32:23 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 14:32:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	fdc_open_mode(const char *pathname, int flags, mode_t mode)
{
	int	fd;

	fd = open(pathname, flags, mode);
	if (fd != -1)
		fd_collector_add(fd, (char *)pathname);
	return (fd);
}
