/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_logical_ops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:57:29 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/13 02:54:08 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*parse_logical_ops(t_token_type **tokens, char ***instructions)
{
	t_ast_node	*left;
	t_ast_node	*node;

	left = parse_pipe(tokens, instructions);
	if (!left)
		return (NULL);
	while (**tokens != TOKEN_EMPTY && (**tokens == TOKEN_AND
			|| **tokens == TOKEN_OR))
	{
		node = ast_new_node(**tokens);
		++(*tokens);
		++(*instructions);
		node->left = left;
		node->right = parse_pipe(tokens, instructions);
		if (!node->right)
			return (ast_empty(node));
		left = node;
	}
	return (left);
}
