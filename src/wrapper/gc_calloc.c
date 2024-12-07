/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:43:01 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 13:02:15 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	*gc_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = gc_malloc(num * size);
	ft_bzero(ptr, num * size);
	return (ptr);
}
