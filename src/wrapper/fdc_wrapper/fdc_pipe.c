/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdc_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:31:29 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 14:31:33 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	fdc_pipe(int pipefd[2])
{
	int	result;

	result = pipe(pipefd);
	if (result == 0)
	{
		fd_collector_add(pipefd[0], "pipe_read");
		fd_collector_add(pipefd[1], "pipe_write");
	}
	return (result);
}
