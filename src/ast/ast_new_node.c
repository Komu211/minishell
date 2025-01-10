/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:50:05 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 13:08:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*ast_new_node(t_token_type type)
{
	t_ast_node	*node;

	node = gc_calloc(1, sizeof(t_ast_node));
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	node->redirection = NULL;
	node->args = NULL;
	return (node);
}
