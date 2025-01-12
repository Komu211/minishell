/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdc_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:32:43 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 14:32:48 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	fdc_open(const char *pathname, int flags)
{
	int	fd;

	fd = open(pathname, flags);
	if (fd != -1)
		fd_collector_add(fd, (char *)pathname);
	return (fd);
}
