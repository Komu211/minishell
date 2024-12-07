/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:05:00 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 12:12:24 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst, void *ptr)
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
			ft_lstdelone(tmp, free);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
