/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:22:54 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/18 09:54:03 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	append_char(char **dest, char c)
{
	char	*tmp;
	size_t	len;

	if (!*dest)
	{
		*dest = gc_calloc(2, sizeof(char));
		(*dest)[0] = c;
		return ;
	}
	len = ft_strlen(*dest);
	tmp = gc_calloc(len + 2, sizeof(char));
	ft_memcpy(tmp, *dest, len);
	tmp[len] = c;
	gc_free(*dest);
	*dest = tmp;
}

static void	append_string(char **dest, const char *src)
{
	char	*tmp;
	size_t	len_dest;
	size_t	len_src;

	if (!src)
		return ;
	if (!*dest)
	{
		*dest = gc_strdup(src);
		return ;
	}
	len_dest = ft_strlen(*dest);
	len_src = ft_strlen(src);
	tmp = gc_calloc(len_dest + len_src + 1, sizeof(char));
	ft_memcpy(tmp, *dest, len_dest);
	ft_memcpy(tmp + len_dest, src, len_src);
	gc_free(*dest);
	*dest = tmp;
}

static void	expand_variable(char **line, char **result, t_list *env_list)
{
	int			i;
	char		var_name[256];
	const char	*expanded;

	i = 0;
	(*line)++;
	while (**line && (ft_isalnum(**line) || **line == '_') && i < 255)
		var_name[i++] = *(*line)++;
	var_name[i] = '\0';
	if (i == 0)
	{
		append_char(result, '$');
		return ;
	}
	expanded = get_env_value(var_name, env_list);
	if (expanded)
		append_string(result, expanded);
}

void	expand_env_vars(char **line, t_list *env_list)
{
	char	*src;
	char	*result;
	int		in_single_quote;

	if (!line || !*line)
		return ;
	src = *line;
	result = NULL;
	in_single_quote = 0;
	while (*src)
	{
		if (*src == '\'')
		{
			in_single_quote = !in_single_quote;
			append_char(&result, *src++);
		}
		else if (!in_single_quote && *src == '$')
			expand_variable(&src, &result, env_list);
		else
			append_char(&result, *src++);
	}
	// gc_free(*line);
	*line = result;
}
