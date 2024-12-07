/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:54 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 21:55:48 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*parse_command(t_token_type **tokens, char ***instructions)
{
	int			arg_count;
	t_ast_node	*node;

	if (!*tokens || **tokens != TOKEN_COMMAND)
		return (NULL);
	node = ast_new_node(TOKEN_COMMAND);
	arg_count = 0;
	while ((*tokens) && (*tokens)[arg_count] == TOKEN_COMMAND)
		arg_count++;
	node->args = gc_calloc(sizeof(char *), (arg_count + 1));
	for (int i = 0; i < arg_count; i++)
	{
		node->args[i] = **instructions;
		++(*instructions);
		++(*tokens);
	}
	return (node);
}
