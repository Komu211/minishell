/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:07:37 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 19:18:54 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	is_hidden(char *str)
{
	if (*str == '\"' || *str == '\'')
		str++;
	if (*str == '.')
		return (1);
	return (0);
}

static char	**add_match(char **matches, int *count, char *name)
{
	matches = gc_realloc(matches, (*count + 1) * sizeof(char *));
	matches[*count] = gc_strjoin_three("\"", name, "\"");
	(*count)++;
	return (matches);
}

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
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_name[0] != '.' || is_hidden(str))
			if (matches_pattern(str, entry->d_name))
				matches = add_match(matches, &count, entry->d_name);
		entry = readdir(dir);
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

	i = -1;
	while (str[++i])
	{
		tmp = expand_wildcard(str[i]);
		if (!tmp)
			continue ;
		gc_free(str[i]);
		str[i] = gc_unsplit(tmp);
	}
	return (str);
}
