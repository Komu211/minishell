/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:00:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 14:34:29 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	gc_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_next;

	while (*lst)
	{
		tmp_next = (*lst)->next;
		gc_lstdelone(*lst, del);
		*lst = tmp_next;
	}
	*lst = NULL;
}
