/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 02:51:59 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 10:16:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	get_mod_len_for_operator(char *line, int i)
{
	int	extra_spaces;

	extra_spaces = 0;
	if (line[i - 1] != ' ')
		extra_spaces++;
	if (line[i + 2] && line[i + 2] != ' ')
		extra_spaces++;
	return (extra_spaces);
}

static int	get_mod_len_for_special(char *line, int i)
{
	int	extra_spaces;

	extra_spaces = 0;
	if (i > 0 && line[i - 1] != ' ')
		extra_spaces++;
	if (line[i + 1] && line[i + 1] != ' ')
		extra_spaces++;
	return (extra_spaces);
}

int	get_mod_len(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (line[i])
	{
		if ((ft_strncmp(&line[i], "&&", 2) == 0 || ft_strncmp(&line[i], "||",
					2) == 0))
		{
			len += get_mod_len_for_operator(line, i);
			i++;
		}
		else if (ft_strchr(SPECIAL_TOKENS, line[i]))
			len += get_mod_len_for_special(line, i);
		i++;
	}
	return (len);
}

void	*transform_line(char *line, char *mod_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if ((ft_strncmp(&line[i], "&&", 2) == 0 || ft_strncmp(&line[i], "||",
					2) == 0) || ft_strncmp(&line[i], ">>", 2) == 0
			|| ft_strncmp(&line[i], "<<", 2) == 0)
			handle_operator(line, mod_line, &i, &j);
		else if (ft_strchr(SPECIAL_TOKENS, line[i]))
			handle_special_token(line, mod_line, &i, &j);
		else if (line[i] == '\'' || line[i] == '\"')
			handle_quotes(line, mod_line, &i, &j);
		else
			mod_line[j++] = line[i++];
	}
	mod_line[j] = '\0';
	return (mod_line);
}
