/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:57:34 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 13:30:49 by obehavka         ###   ########.fr       */
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
