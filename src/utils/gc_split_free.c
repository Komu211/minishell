/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:20:59 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 16:26:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void gc_split_free(char ***split)
{
	int	i;

	i = 0;
	while ((*split)[i])
	{
		gc_free((*split)[i]);
		i++;
	}
	gc_free(*split);
	*split = NULL;
}
