/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:23:31 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 12:32:02 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	garbage_collector_add(void *ptr)
{
	t_list	*new;

	new = ft_lstnew(ptr);
	if (!new)
		error_handler("Failed to allocate memory for garbage collector", 1);
	ft_lstadd_front(garbage_holder(), new);
}
