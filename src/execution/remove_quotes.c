/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:50:37 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/19 17:43:53 by kmuhlbau         ###   ########.fr       */
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
