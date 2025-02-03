/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:53:09 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 11:16:26 by kmuhlbau         ###   ########.fr       */
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

static int	validate_quotes(char *line)
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
				return ((*get_mini())->exit_status = 2, ft_putstr_fd("syntax error: unclosed quote\n", 2), 1);
		}
		++i;
	}
	return (0);
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

void	ast_init(t_ast_node **node, char *line, t_minishell *minishell)
{
	char			**split_line;
	t_token_type	*tokens;
	char			*mod_line;

	if (validate_quotes(line))
		return ;
	mod_line = gc_calloc(get_mod_len(line) + 1, sizeof(char));
	transform_line(line, mod_line);
	split_line = gc_split(mod_line);
	tokens = gc_tokenizer(split_line);
	*node = ast_build(tokens, split_line, minishell);
	gc_split_free(&split_line);
	gc_free(mod_line);
	gc_free(tokens);
}
