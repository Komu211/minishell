/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:57:34 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 13:36:45 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	gc_free(void *ptr)
{
	if (!ptr)
		return ;
	if (!garbage_collector_remove(ptr))
		error_handler("Possible double free:\nTrying to gc_free pointer that was not gc_malloced, gc_calloced or gc_realloced", 1);
}
