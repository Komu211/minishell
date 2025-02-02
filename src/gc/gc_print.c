/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:22:38 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/02 12:23:37 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	garbage_collector_print(void)
{
	t_list	*tmp;
	size_t	i;

	tmp = *garbage_holder();
	i = 0;
	while (tmp)
	{
		printf("Pointer %zu: %p, %s\n", i, tmp->content, (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
}
