/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:50:37 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/20 15:28:04 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	handle_quote(char **src, char **dst, char quote)
{
	(*src)++;
	while (**src && **src != quote)
	{
		*(*dst)++ = *(*src)++;
	}
	if (**src == quote)
		(*src)++;
}

void	remove_quotes(char **str)
{
	char	*src;
	char	*dst;

	src = *str;
	dst = *str;
	while (*src)
	{
		if (*src == '\'')
			handle_quote(&src, &dst, '\'');
		else if (*src == '\"')
			handle_quote(&src, &dst, '\"');
		else
			*dst++ = *src++;
	}
	*dst = '\0';
}
