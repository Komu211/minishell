/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:00:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/20 15:23:37 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_collector.h"

int	fd_collector_remove(int fd)
{
	t_list	**holder;
	t_list	*current;

	holder = fd_collector();
	current = *holder;
	if (!ft_lstcontains(current, &fd))
		return (0);
	gc_lstremove(holder, &fd);
	return (1);
}
