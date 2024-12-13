/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:54 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/13 02:53:25 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*parse_command(t_token_type **tokens, char ***instructions)
{
	int			arg_count;
	t_ast_node	*node;
	int			i;

	if (!*tokens || **tokens != TOKEN_COMMAND)
		return (NULL);
	node = ast_new_node(TOKEN_COMMAND);
	arg_count = 0;
	while ((*tokens) && (*tokens)[arg_count] == TOKEN_COMMAND)
		arg_count++;
	node->args = gc_calloc(sizeof(char *), (arg_count + 1));
	i = 0;
	while (i < arg_count)
	{
		node->args[i] = **instructions;
		++(*instructions);
		++(*tokens);
		i++;
	}
	return (node);
}
