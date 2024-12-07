/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:14:13 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 12:14:41 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcontains(t_list *lst, void *ptr)
{
	while (lst)
	{
		if (lst->content == ptr)
			return (1);
		lst = lst->next;
	}
	return (0);
}
