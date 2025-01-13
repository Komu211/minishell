/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:22:54 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/13 11:55:17 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	expand_env_vars(char **line, t_list *env_list)
{
	char	*src;
	char	*dst;
	char	*new_line;
	size_t	len;
	int		in_single_quote;
	char	var_name[256];
	int		i;
	t_env	*env_search;
	char	*expanded;
	t_list	*curr;

	if (!line || !*line)
		return ;
	src = *line;
	// Allocate a buffer larger than the original (in case of expansions).
	// For a real shell, you might use a dynamic approach instead.
	new_line = gc_calloc(ft_strlen(src) * 4 + 1, sizeof(char));
	if (!new_line)
		return ;
	dst = new_line;
	in_single_quote = 0;
	while (*src)
	{
		if (*src == '\'') // Toggle single-quote mode (disables expansions)
		{
			in_single_quote = !in_single_quote;
			*dst++ = *src++;
		}
		else if (!in_single_quote && *src == '$') // Expand $VAR
		{
			i = 0;
			src++; // skip '$'
			while (*src && (ft_isalnum(*src) || *src == '_') && i < 255)
				var_name[i++] = *src++;
			var_name[i] = '\0';
			if (i == 0)
			{
				*dst++ = '$'; // Just a lone '$'
				continue ;
			}
			{
				// Lookup var in env_list
				env_search = NULL;
				expanded = NULL;
				curr = (t_list *)env_list;
				while (curr)
				{
					env_search = (t_env *)curr->content;
					if (ft_strcmp(env_search->key, var_name) == 0)
					{
						expanded = env_search->value;
						break ;
					}
					curr = curr->next;
				}
				if (!expanded)
					expanded = ""; // If not found, expand to empty
				len = ft_strlen(expanded);
				ft_memcpy(dst, expanded, len);
				dst += len;
			}
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	// gc_free(*line);
	*line = new_line;
}
