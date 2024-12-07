/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:23:35 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 12:25:42 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	gc_empty(void)
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

