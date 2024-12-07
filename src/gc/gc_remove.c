/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:02:14 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 12:33:30 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

int	garbage_collector_remove(void *ptr)
{
	if (!ft_lstcontains(*garbage_holder(), ptr))
		return (0);
	ft_lstremove(garbage_holder(), ptr);
	return (1);
}
