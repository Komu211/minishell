/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:53:09 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/08 22:23:21 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_token_type	get_token_type(char *word)
{
	if (!ft_strcmp(word, "&&"))
		return (TOKEN_AND);
	if (!ft_strcmp(word, "||"))
		return (TOKEN_OR);
	if (!ft_strcmp(word, "|"))
		return (TOKEN_PIPE);
	if (!ft_strcmp(word, "("))
		return (TOKEN_PAREN_OPEN);
	if (!ft_strcmp(word, ")"))
		return (TOKEN_PAREN_CLOSE);
	if (!ft_strcmp(word, "<"))
		return (TOKEN_REDIRECT_IN);
	if (!ft_strcmp(word, ">"))
		return (TOKEN_REDIRECT_OUT);
	return (TOKEN_COMMAND);
}

static t_token_type	*gc_tokenizer(char **split_line)
{
	t_token_type	*tokens;
	int				i;

	i = 0;
	while (split_line[i])
		++i;
	tokens = gc_calloc(i + 1, sizeof(t_token_type));
	i = -1;
	while (split_line[++i])
		tokens[i] = get_token_type(split_line[i]);
	tokens[i] = TOKEN_EMPTY;
	return (tokens);
}

static int	get_mod_len(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if ((ft_strncmp(&line[i], "&&", 2) == 0 || ft_strncmp(&line[i], "||",
					2) == 0) && line[i + 2] != ' ')
			len += 2;
		else if (ft_strchr(SPECIAL_TOKENS, line[i]) && line[i + 1] != ' ')
			len += 1;
		++len;
		++i;
	}
	return (len);
}

static void	*transform_line(char *line, char *mod_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if ((ft_strncmp(&line[i], "&&", 2) == 0 || ft_strncmp(&line[i], "||",
					2) == 0) && line[i + 2] != ' ')
		{
			mod_line[j++] = ' ';
			mod_line[j++] = line[i++];
			mod_line[j++] = line[i++];
			mod_line[j++] = ' ';
		}
		else if (ft_strchr(SPECIAL_TOKENS, line[i]) && line[i + 1] != ' ')
		{
			mod_line[j++] = ' ';
			mod_line[j++] = line[i++];
			mod_line[j++] = ' ';
		}
		else
			mod_line[j++] = line[i++];
	}
	return (mod_line);
}

void	ast_init(t_ast_node **node, char *line)
{
	char			**split_line;
	t_token_type	*tokens;
	char			*mod_line;

	mod_line = gc_calloc(get_mod_len(line) + 1, sizeof(char));
	transform_line(line, mod_line);
	printf("mod_line: %s\n", mod_line);
	split_line = gc_split(mod_line);
	tokens = gc_tokenizer(split_line);
	*node = ast_build(tokens, split_line);
	gc_free(split_line);
	gc_free(mod_line);
	gc_free(tokens);
}
