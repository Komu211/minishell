/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:53:09 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:26:18 by kmuhlbau         ###   ########.fr       */
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
		return (TOKEN_PARAN_OPEN);
	if (!ft_strcmp(word, ")"))
		return (TOKEN_PARAN_CLOSE);
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
	return (tokens);
}

void	ast_init(t_ast_node **node, char *line)
{
	char			**split_line;
	t_token_type	*tokens;

	split_line = gc_split(line);
	tokens = gc_tokenizer(split_line);
	*node = ast_build(tokens, split_line);
}
