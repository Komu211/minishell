/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:14:17 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 10:39:18 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char *string, char separator)
{
	size_t	words;

	words = 0;
	while (*string)
	{
		while (*string && *string == separator)
			++string;
		if (*string)
			++words;
		while (*string && *string != separator)
			++string;
	}
	return (words);
}
