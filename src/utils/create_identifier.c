/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:33:31 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 13:26:31 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	convert_buffer_to_hex(char *result, char *buffer)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		result[i * 2] = ((buffer[i] >> 4) & 0x0F) + '0';
		if (result[i * 2] > '9')
			result[i * 2] = result[i * 2] + 7;
		result[i * 2] = result[i * 2] + 7;
		result[i * 2 + 1] = (buffer[i] & 0x0F) + '0';
		if (result[i * 2 + 1] > '9')
			result[i * 2 + 1] = result[i * 2 + 1] + 7;
		i++;
	}
	result[12] = '\0';
}

char	*generate_unique_identifier(void)
{
	char	*result;
	int		fd;
	char	buffer[6];

	result = gc_malloc(13);
	if (!result)
		return (NULL);
	fd = fdc_open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		gc_free(result);
		return (NULL);
	}
	if (read(fd, buffer, 6) != 6)
	{
		fdc_close(fd);
		gc_free(result);
		return (NULL);
	}
	fdc_close(fd);
	convert_buffer_to_hex(result, buffer);
	return (result);
}
