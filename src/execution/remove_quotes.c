/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:50:37 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/19 15:28:06 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	remove_quotes(char **str)
{
	char	*src;
	char	*dst;

	src = *str;
	dst = *str;
	while (*src)
	{
		if (*src == '\'')
		{
			src++;
			while (*src && *src != '\'')
				*dst++ = *src++;
			if (*src == '\'')
				src++;
		}
		else if (*src == '\"')
		{
			src++;
			while (*src && *src != '\"')
				*dst++ = *src++;
			if (*src == '\"')
				src++;
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
}
