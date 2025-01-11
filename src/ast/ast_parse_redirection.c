/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:15:00 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 18:50:38 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// static t_redirection_type	get_redirection_type(t_token_type token)
// {
// 	if (token == TOKEN_REDIRECT_IN)
// 		return (REDIRECT_IN);
// 	if (token == TOKEN_REDIRECT_OUT)
// 		return (REDIRECT_OUT);
// 	if (token == TOKEN_REDIRECT_OUT_APPEND)
// 		return (REDIRECT_OUT_APPEND);
// 	return (REDIRECT_HERE_DOC);
// }

t_ast_node	*parse_redirection(t_token_type **tokens, char ***instructions)
{
	t_ast_node	*left;
	t_ast_node	*node;

	left = parse_parentheses(tokens, instructions);
	if (!left)
		return (NULL);
	while (**tokens != TOKEN_EMPTY && is_redirection(**tokens))
	{
		node = ast_new_node(**tokens);
		++(*tokens);
		++(*instructions);
		node->left = left;
		node->right = parse_command(tokens, instructions);
		if (!node->right)
			return (ast_empty(node));
		left = node;
	}
	return (left);
}
