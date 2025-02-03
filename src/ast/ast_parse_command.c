/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:54 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 10:22:13 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	handle_command_token(t_ast_node *node, t_token_type **tokens,
		char ***instructions, int *arg_count)
{
	node->args[(*arg_count)++] = gc_strdup(**instructions);
	++(*tokens);
	++(*instructions);
}

static int	handle_redirection_token(t_ast_node *node, t_token_type **tokens,
		char ***instructions, t_token_type current_token)
{
	t_redirection	*redirection;

	redirection = parse_redirection(tokens, instructions);
	if (!redirection)
		return (0);
	if (is_redirection_in(current_token))
		add_redirection(&node->redirections_in, redirection);
	else
		add_redirection(&node->redirections_out, redirection);
	return (1);
}

t_ast_node	*parse_command(t_token_type **tokens, char ***instructions)
{
	t_ast_node		*node;
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
			handle_command_token(node, tokens, instructions, &arg_count);
			has_command = 1;
		}
		else if (!handle_redirection_token(node, tokens, instructions,
				current_token))
			return (ast_empty(node));
	}
	if (!has_command && !node->redirections_in && !node->redirections_out)
		return (ast_empty(node));
	return (node);
}
