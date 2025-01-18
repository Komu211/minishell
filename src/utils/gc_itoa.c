/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:09:47 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/18 10:43:17 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	if (!len)
		len = 1;
	return (len);
}

char	*gc_itoa(int n)
{
	int		n_temp;
	char	*ret_ptr;
	size_t	num_len;

	num_len = numlen(n);
	ret_ptr = (char *)gc_calloc(num_len + 1 + (n < 0), sizeof(char));
	if (n > 0)
		n = -n;
	else if (n < 0)
	{
		*ret_ptr = '-';
		++num_len;
	}
	else
		ret_ptr[0] = '0';
	n_temp = n;
	while (n_temp)
	{
		ret_ptr[--num_len] = ((n_temp % 10) * (-1)) + '0';
		n_temp /= 10;
	}
	return (ret_ptr);
}
