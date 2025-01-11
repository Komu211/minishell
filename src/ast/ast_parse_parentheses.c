/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_parentheses.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:33:26 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 15:52:50 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// static int	is_redirection(t_token_type **tokens)
// {
// 	return (**tokens == TOKEN_REDIRECT_IN || **tokens == TOKEN_REDIRECT_OUT
// 		|| **tokens == TOKEN_REDIRECT_OUT_APPEND
// 		|| **tokens == TOKEN_REDIRECT_HERE_DOC);
// }

t_ast_node	*parse_parentheses(t_token_type **tokens, char ***instructions)
{
	t_ast_node	*node;

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
		return (node);
	}
	return (parse_command(tokens, instructions));
}
