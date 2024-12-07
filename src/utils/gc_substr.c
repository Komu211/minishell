/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:12:41 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:31:41 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*gc_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	else if (s_len < start + len)
		len = s_len - start;
	return_str = (char *)gc_malloc(sizeof(char) * (len + 1));
	if (!return_str)
		return (NULL);
	if (len == 0)
		*return_str = '\0';
	else
		ft_strlcpy(return_str, s + start, len + 1);
	return (return_str);
}
