/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdc_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:30:03 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 14:30:08 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	fdc_dup(int oldfd)
{
	int	newfd;

	newfd = dup(oldfd);
	if (newfd != -1)
		fd_collector_add(newfd, "dup_fd");
	return (newfd);
}
