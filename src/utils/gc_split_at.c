/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:12:07 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 16:38:14 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_word_count(const char *string, char c)
{
	size_t	words;

	words = 0;
	while (*string)
	{
		while (*string && *string == c)
			++string;
		if (*string)
			++words;
		while (*string && *string != c)
			++string;
	}
	return (words);
}

static size_t	get_word_size(const char *s, char c)
{
	size_t	size;
	char	quote;

	size = 0;
	while (s[size] && s[size] != c)
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

char	**gc_split_at(const char *s, char c)
{
	size_t	word_size;
	size_t	word_count;
	char	**ret_ptr;
	char	**tmp_ptr;

	word_count = ft_word_count(s, c);
	ret_ptr = gc_calloc(sizeof(char *), (word_count + 1));
	if (!ret_ptr)
		return (NULL);
	tmp_ptr = ret_ptr;
	while (word_count--)
	{
		while (*s && *s == c)
			++s;
		word_size = get_word_size(s, c);
		*tmp_ptr++ = gc_substr(s, 0, word_size);
		s += word_size;
	}
	return (ret_ptr);
}
