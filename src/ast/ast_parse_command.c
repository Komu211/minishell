/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:54 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 12:39:38 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*parse_command(t_token_type **tokens, char ***instructions)
{
	t_ast_node		*node;
	t_redirection	*redirection;
	int				has_command;
	t_token_type	current_token;
	int				arg_count;

	node = ast_new_node(TOKEN_COMMAND);
	has_command = 0;
	arg_count = 0;
	if (*tokens && (**tokens == TOKEN_COMMAND || is_redirection(**tokens)))
		node->args = gc_calloc(count_arguments(*tokens), sizeof(char *));
	while (*tokens && (**tokens == TOKEN_COMMAND || is_redirection(**tokens)))
	{
		current_token = **tokens;
		if (current_token == TOKEN_COMMAND)
		{
			node->args[arg_count++] = gc_strdup(**instructions);
			has_command = 1;
			++(*tokens);
			++(*instructions);
		}
		else
		{
			redirection = parse_redirection(tokens, instructions);
			if (!redirection)
				return (ast_empty(node));
			if (is_redirection_in(current_token))
				add_redirection(&node->redirections_in, redirection);
			else
				add_redirection(&node->redirections_out, redirection);
		}
	}
	if (!has_command && !node->redirections_in && !node->redirections_out)
		return (ast_empty(node));
	return (node);
}
