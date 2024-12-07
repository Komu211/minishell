/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:41:14 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 15:42:26 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void   *gc_strdup(const char *s)
{
	char    *str;
	size_t  len;

	len = ft_strlen(s);
	str = gc_malloc(len + 1);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}
