/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdc_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:31:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 10:45:00 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	fdc_close(int fd)
{
	if (fd <= 2)
		return (0);
	if (fd_collector_remove(fd))
		return (0);
	return (close(fd));
}
