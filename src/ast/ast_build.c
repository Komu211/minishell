/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:19:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 22:00:11 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*ast_build(t_token_type *tokens, char **split_line)
{
	t_ast_node	*node;

	if (!tokens)
		return (NULL);
	node = parse_logical_ops(&tokens, &split_line);
	return (node);
}
