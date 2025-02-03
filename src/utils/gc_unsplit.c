/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:20:48 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/03 18:42:46 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*gc_unsplit(char **split)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = 1;
	i = 0;
	while (split[i])
		len += ft_strlen(split[i++]) + 1;
	str = gc_calloc(len, sizeof(char));
	i = 0;
	j = 0;
	while (split[i])
	{
		ft_memcpy(str + j, split[i], ft_strlen(split[i]));
		j += ft_strlen(split[i]) + 1;
		if (j)
			str[j - 1] = ' ';
		i++;
	}
	if (j)
		str[j - 1] = '\0';
	return (str);
}
