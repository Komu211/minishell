/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:00:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 09:50:33 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static size_t	ft_word_count(const char *string)
{
	size_t	words;

	words = 0;
	while (*string)
	{
		while (*string && ft_isspace(*string))
			++string;
		if (*string)
			++words;
		while (*string && !ft_isspace(*string))
			++string;
	}
	return (words);
}

static size_t	get_word_size(const char *s)
{
	size_t	size;
	char	quote;

	size = 0;
	while (s[size] && !ft_isspace(s[size]))
	{
		if (s[size] == '\'' || s[size] == '\"')
		{
			quote = s[size++];
			while (s[size] && s[size] != quote)
				size++;
			if (s[size])
				size++;
		}
		else
			size++;
	}
	return (size);
}

char	**gc_split(const char *s)
{
	size_t	word_size;
	size_t	word_count;
	char	**ret_ptr;
	char	**tmp_ptr;

	word_count = ft_word_count(s);
	ret_ptr = gc_calloc(sizeof(char *), (word_count + 1));
	if (!ret_ptr)
		return (NULL);
	tmp_ptr = ret_ptr;
	while (word_count--)
	{
		while (ft_isspace(*s))
			++s;
		word_size = get_word_size(s);
		*tmp_ptr++ = gc_substr(s, 0, word_size);
		s += word_size;
	}
	return (ret_ptr);
}
