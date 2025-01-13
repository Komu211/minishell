/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:53:09 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/13 11:52:02 by obehavka         ###   ########.fr       */
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

static char			*g_token_names[] = {[TOKEN_AND] = "AND", [TOKEN_OR] = "OR",
				[TOKEN_PIPE] = "PIPE", [TOKEN_PAREN_OPEN] = "PAREN_OPEN",
				[TOKEN_PAREN_CLOSE] = "PAREN_CLOSE",
				[TOKEN_REDIRECT_IN] = "REDIRECT_IN",
				[TOKEN_REDIRECT_OUT] = "REDIRECT_OUT",
				[TOKEN_REDIRECT_OUT_APPEND] = "REDIRECT_OUT_APPEND",
				[TOKEN_REDIRECT_HERE_DOC] = " REDIRECT_HERE_DOC",
				[TOKEN_COMMAND] = "COMMAND", [TOKEN_EMPTY] = "EMPTY"};

static void	validate_quotes(char *line)
{
	char	quote;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				++i;
			if (!line[i])
				error_handler("syntax error: unclosed quote\n", 0);
		}
		++i;
	}
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
	{
		tokens[i] = get_token_type(split_line[i]);
		printf("Token: %s, word: %s\n", g_token_names[tokens[i]],
			split_line[i]);
	}
	tokens[i] = TOKEN_EMPTY;
	return (tokens);
}

void	ast_init(t_ast_node **node, char *line, t_list *env_list)
{
	char			**split_line;
	t_token_type	*tokens;
	char			*mod_line;

	validate_quotes(line);
	expand_env_vars(&line, env_list);
	mod_line = gc_calloc(get_mod_len(line) + 1, sizeof(char));
	transform_line(line, mod_line);
	split_line = gc_split(mod_line);
	tokens = gc_tokenizer(split_line);
	*node = ast_build(tokens, split_line);
	gc_split_free(&split_line);
	gc_free(mod_line);
	gc_free(tokens);
}
