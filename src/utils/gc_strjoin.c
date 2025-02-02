/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:18:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 16:46:40 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*gc_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	str = gc_malloc(len1 + len2 + len3 + 1);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	ft_memcpy(str + len1 + len2, s3, len3);
	str[len1 + len2 + len3] = '\0';
	return (str);
}

char	*gc_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = gc_malloc(len1 + len2 + 1);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
