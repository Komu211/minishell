/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:57:34 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/20 15:23:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	gc_free(void *ptr)
{
	if (!ptr)
		return ;
	if (!garbage_collector_remove(ptr))
		error_handler("Possible double free:\n"
			"Trying to gc_free pointer that was not gc_malloced, "
			"gc_calloced or gc_realloced ",
			1);
}
