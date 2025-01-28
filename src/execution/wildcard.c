/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:07:37 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/21 09:54:44 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	matches_pattern(const char *pattern, const char *string)
{
	while (*pattern && *string)
	{
		if (*pattern == '*')
		{
			while (*pattern == '*')
				pattern++;
			if (*pattern == '\0')
				return (1);
			while (*string)
			{
				if (matches_pattern(pattern, string))
					return (1);
				string++;
			}
			return (matches_pattern(pattern, string));
		}
		if (*pattern != *string)
			return (0);
		pattern++;
		string++;
	}
	while (*pattern == '*')
		pattern++;
	return (*pattern == '\0' && *string == '\0');
}

static char	**join_matches(char **strs)
{
	int		count;
	char	**result;
	int		i;

	count = 0;
	while (strs[count])
		count++;
	result = gc_malloc((count + 1) * sizeof(char *));
	i = -1;
	while (strs[++i])
		result[i] = gc_strdup(strs[i]);
	result[i] = NULL;
	return (result);
}

static char	*expand_wildcard(char *str)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matches;
	int				count;
	char			*result;

	matches = NULL;
	count = 0;
	dir = opendir(".");
	if (!dir)
		return (str);
	while ((entry = readdir(dir)))
	{
		if (matches_pattern(str, entry->d_name))
		{
			matches = gc_realloc(matches, (count + 1) * sizeof(char *));
			matches[count] = gc_strdup(entry->d_name);
			count++;
		}
	}
	closedir(dir);
	if (count == 0)
		return (str);
	matches = gc_realloc(matches, (count + 1) * sizeof(char *));
	matches[count] = NULL;
	result = *join_matches(matches);
	return (result);
}

char	**expand_wildcards(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = expand_wildcard(str[i]);
	return (str);
}
