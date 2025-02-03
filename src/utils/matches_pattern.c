/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matches_pattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:04:26 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 19:19:04 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	handle_quotes(const char **pattern, t_quotes *quotes)
{
	if (**pattern == '\'' && !quotes->in_double)
	{
		(*pattern)++;
		quotes->in_single = !quotes->in_single;
		return (1);
	}
	if (**pattern == '\"' && !quotes->in_single)
	{
		(*pattern)++;
		quotes->in_double = !quotes->in_double;
		return (1);
	}
	return (0);
}

int	matches_pattern(const char *pattern, const char *string)
{
	t_quotes	quotes;

	quotes = (t_quotes){0, 0};
	while (*pattern && *string)
	{
		if (handle_quotes(&pattern, &quotes))
			continue;
		if (*pattern == '*' && !quotes.in_double && !quotes.in_single)
		{
			while (*pattern == '*')
				pattern++;
			if (*pattern == '\0')
				return (1);
			while (*string)
				if (matches_pattern(pattern, string++))
					return (--string, 1);
			return (matches_pattern(pattern, string));
		}
		if (*pattern++ != *string++)
			return (0);
	}
	while (*pattern == '*' || (quotes.in_double && *pattern == '\"')
		|| (quotes.in_single && *pattern == '\''))
		pattern++;
	return (*pattern == '\0' && *string == '\0');
}
