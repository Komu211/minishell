/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:23:35 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 22:11:16 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	garbage_collector_empty(void)
{
	t_list	**holder;
	t_list	*tmp;

	holder = garbage_holder();
	while (*holder)
	{
		tmp = *holder;
		*holder = (*holder)->next;
		ft_lstdelone(tmp, free);
	}
}
