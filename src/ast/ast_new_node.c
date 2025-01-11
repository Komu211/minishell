/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:50:05 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 15:53:13 by obehavka         ###   ########.fr       */
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
	node->redirections_in = NULL;
	node->redirections_out = NULL;
	node->args = NULL;
	return (node);
}
