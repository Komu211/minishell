/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_parentheses.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:33:26 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 22:02:42 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

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
