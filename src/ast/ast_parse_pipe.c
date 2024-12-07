/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:28:07 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 21:57:56 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*parse_pipe(t_token_type **tokens, char ***instructions)
{
	t_ast_node	*left;
	t_ast_node	*node;

	left = parse_parentheses(tokens, instructions);
	if (!left)
		return (NULL);
	while (**tokens != TOKEN_EMPTY && **tokens == TOKEN_PIPE)
	{
		node = ast_new_node(TOKEN_PIPE);
		++(*tokens);
		++(*instructions);
		node->left = left;
		node->right = parse_logical_ops(tokens, instructions);
		if (!node->right)
			return (ast_empty(node));
		left = node;
	}
	return (left);
}
