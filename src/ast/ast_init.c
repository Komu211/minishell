/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:53:09 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 11:59:16 by obehavka         ###   ########.fr       */
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
	if (!ft_strcmp(word, ">>"))
		return (TOKEN_REDIRECT_OUT_APPEND);
	if (!ft_strcmp(word, "<<"))
		return (TOKEN_REDIRECT_HERE_DOC);
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

void	ast_init(t_ast_node **node, char *line)
{
	char			**split_line;
	t_token_type	*tokens;
	char			*mod_line;

	mod_line = gc_calloc(get_mod_len(line) + 1, sizeof(char));
	transform_line(line, mod_line);
	split_line = gc_split(mod_line);
	tokens = gc_tokenizer(split_line);
	*node = ast_build(tokens, split_line);
	gc_free(split_line);
	gc_free(mod_line);
	gc_free(tokens);
}
