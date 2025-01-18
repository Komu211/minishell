/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:54:15 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/18 15:54:50 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	append_char(char **dest, char c)
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

void	append_string(char **dest, const char *src)
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
