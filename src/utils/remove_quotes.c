/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:50:37 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/02 18:32:27 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int	remove_quotes(char **str)
{
	char	*src;
	char	*dst;
	int		orig_len;

	orig_len = ft_strlen(*str);
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
	return (orig_len != ft_strlen(*str));
}
