/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:44:19 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/03 15:38:22 by obehavka         ###   ########.fr       */
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
	new_ptr = gc_calloc(size + 1, 1);
	if (ptr)
		ft_memcpy(new_ptr, ptr, size);
	gc_free(ptr);
	return (new_ptr);
}
