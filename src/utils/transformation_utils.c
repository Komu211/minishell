/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:16:25 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 11:57:13 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handle_transform_operator(char *line, char *mod_line, int *i, int *j)
{
	if ((*i) > 0 && line[(*i) - 1] != ' ')
		mod_line[(*j)++] = ' ';
	mod_line[(*j)++] = line[(*i)];
	mod_line[(*j)++] = line[(*i) + 1];
	if (line[(*i) + 2] && line[(*i) + 2] != ' ')
		mod_line[(*j)++] = ' ';
	(*i) += 2;
}

void	handle_transform_special_token(char *line, char *mod_line, int *i, int *j)
{
	if (*i > 0 && line[*i - 1] != ' ')
		mod_line[(*j)++] = ' ';
	mod_line[(*j)++] = line[(*i)++];
	if (line[*i] && line[*i] != ' ')
		mod_line[(*j)++] = ' ';
}

void	handle_transform_quotes(char *line, char *mod_line, int *i, int *j)
{
	char	quote_char;

	quote_char = line[*i];
	mod_line[(*j)++] = line[(*i)++];
	while (line[*i] && line[*i] != quote_char)
		mod_line[(*j)++] = line[(*i)++];
	if (line[*i])
		mod_line[(*j)++] = line[(*i)++];
}
