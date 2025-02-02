/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:07:37 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 15:47:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <dirent.h>

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

// static char	**join_matches(char **strs)
// {
// 	int		count;
// 	char	**result;
// 	int		i;

// 	count = 0;
// 	while (strs[count])
// 		count++;
// 	result = gc_malloc((count + 1) * sizeof(char *));
// 	i = -1;
// 	while (strs[++i])
// 		result[i] = gc_strdup(strs[i]);
// 	result[i] = NULL;
// 	return (result);
// }

static char	**expand_wildcard(char *str)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matches;
	int				count;

	matches = NULL;
	count = 0;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue ;
		if (matches_pattern(str, entry->d_name))
		{
			matches = gc_realloc(matches, (count + 1) * sizeof(char *));
			matches[count] = gc_strdup(entry->d_name);
			count++;
		}
	}
	closedir(dir);
	if (count == 0)
		return (NULL);
	matches = gc_realloc(matches, (count + 1) * sizeof(char *));
	matches[count] = NULL;
	return (matches);
}

char	**expand_wildcards(char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[++i])
	{
		tmp = expand_wildcard(str[i]);
		if (!tmp)
			continue ;
		str[i] = gc_unsplit(tmp);
	}
	return (str);
}
