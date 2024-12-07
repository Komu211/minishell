/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:02:00 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 19:04:45 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	get_result_base(const char *str, int base)
{
	int		result;
	int		digit;

	result = 0;
	while (ft_isdigit(*str)
		|| (*str >= 'a' && *str < 'a' + base - 10)
		|| (*str >= 'A' && *str < 'A' + base - 10))
	{
		digit = *str - '0';
		if (digit > 9)
			digit = ft_tolower(*str) - 'a' + 10;
		result = result * base + digit;
		++str;
	}
	return (result);
}

int	ft_atoi_base(const char *str, int base)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	if (base < 2 || base > 36)
		return (0);
	while (ft_is_space(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	if (base == 16 && (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "0X", 2)))
		str += 2;
	result = get_result_base(str, base);
	return (result * sign);
}
