/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:44:19 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 13:14:42 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	*gc_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		gc_free(ptr);
		return (NULL);
	}
	new_ptr = gc_malloc(size);
	if (ptr)
		ft_memcpy(new_ptr, ptr, size);
	gc_free(ptr);
	return (new_ptr);
}
