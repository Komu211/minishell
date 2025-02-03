/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:44:19 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/03 17:51:47 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	*gc_realloc(void *ptr, size_t size, size_t copy_size)
{
	void	*new_ptr;

	if (size == 0)
	{
		gc_free(ptr);
		return (NULL);
	}
	new_ptr = gc_calloc(size + 1, 1);
	if (ptr)
		ft_memcpy(new_ptr, ptr, copy_size);
	gc_free(ptr);
	return (new_ptr);
}
