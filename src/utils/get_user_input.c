/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:38:04 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 17:05:18 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_user_input(char *prompt)
{
	char	*user_in;
	char	*line;

	if (isatty(STDIN_FILENO))
		user_in = readline(prompt);
	else
	{
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			user_in = ft_strtrim(line, "\n");
			free(line);
		}
		else
			user_in = NULL;
	}
	return (user_in);
}
