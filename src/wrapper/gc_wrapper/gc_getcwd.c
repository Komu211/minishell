/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:28:35 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 17:50:27 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

char	*gc_getcwd(char *buf)
{
	static size_t	size = 1024;
	char			*str;

	if (buf == NULL)
		buf = gc_malloc(size);
	str = getcwd(buf, size);
	while (!str && errno == ERANGE)
	{
		size *= 2;
		str = gc_realloc(buf, size, size / 2);
		str = getcwd(buf, size);
	}
	if (!str)
		error_handler("getcwd failed", 1);
	return (str);
}
