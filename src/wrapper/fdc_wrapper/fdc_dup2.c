/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdc_dup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:29:49 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 14:31:49 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	fdc_dup2(int oldfd, int newfd)
{
	int result;

	result = dup2(oldfd, newfd);
	if (result != -1)
	{
		fd_collector_remove(newfd);
		fd_collector_add(newfd, "dup2_fd");
	}
	return (result);
}

