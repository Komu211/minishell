/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_parentheses.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:33:26 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 12:33:16 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*parse_parentheses(t_token_type **tokens, char ***instructions)
{
	t_ast_node		*node;
	t_redirection	*redirection;
	t_token_type	tmp;

	if (!(*tokens))
		return (NULL);
	if (**tokens == TOKEN_PAREN_OPEN)
	{
		++(*tokens);
		++(*instructions);
		node = parse_logical_ops(tokens, instructions);
		if (!node || **tokens == TOKEN_EMPTY || **tokens != TOKEN_PAREN_CLOSE)
			return (ast_empty(node));
		++(*tokens);
		++(*instructions);
		while (*tokens && is_redirection(**tokens))
		{
			tmp = **tokens;
			redirection = parse_redirection(tokens, instructions);
			if (!redirection)
				return (ast_empty(node));
			if (is_redirection_in(tmp))
				add_redirection(&node->redirections_in, redirection);
			else
				add_redirection(&node->redirections_out, redirection);
		}
		if (**tokens == TOKEN_PAREN_OPEN || **tokens == TOKEN_COMMAND)
			return (ast_empty(node));
		return (node);
	}
	return (parse_command(tokens, instructions));
}
