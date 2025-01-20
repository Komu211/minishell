/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:00:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/20 15:22:41 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	gc_lstremove(t_list **lst, void *ptr)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp->content == ptr)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*lst = tmp->next;
			gc_free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
