/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_parentheses.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:33:26 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 10:28:17 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_ast_node	*handle_parentheses_content(t_token_type **tokens,
		char ***instructions)
{
	t_ast_node	*node;

	++(*tokens);
	++(*instructions);
	node = parse_logical_ops(tokens, instructions);
	if (!node || **tokens != TOKEN_PAREN_CLOSE)
		return (ast_empty(node));
	++(*tokens);
	++(*instructions);
	return (node);
}

static int	handle_redirection_token(t_ast_node *node, t_token_type **tokens,
		char ***instructions, t_token_type tmp)
{
	t_redirection	*redirection;

	redirection = parse_redirection(tokens, instructions);
	if (!redirection)
		return (0);
	if (is_redirection_in(tmp))
		add_redirection(&node->redirections_in, redirection);
	else
		add_redirection(&node->redirections_out, redirection);
	return (1);
}

static t_ast_node	*handle_redirections(t_ast_node *node,
		t_token_type **tokens, char ***instructions)
{
	t_token_type	tmp;

	while (*tokens && is_redirection(**tokens))
	{
		tmp = **tokens;
		if (!handle_redirection_token(node, tokens, instructions, tmp))
			return (ast_empty(node));
	}
	if (**tokens == TOKEN_PAREN_OPEN || **tokens == TOKEN_COMMAND)
		return (ast_empty(node));
	return (node);
}

t_ast_node	*parse_parentheses(t_token_type **tokens, char ***instructions)
{
	t_ast_node	*node;

	if (!(*tokens))
		return (NULL);
	if (**tokens == TOKEN_PAREN_OPEN)
	{
		node = handle_parentheses_content(tokens, instructions);
		if (!node)
			return (NULL);
		return (handle_redirections(node, tokens, instructions));
	}
	return (parse_command(tokens, instructions));
}
