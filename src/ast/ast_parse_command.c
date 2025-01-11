/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:54 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 16:29:05 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	is_redirection_in(t_token_type *tokens)
{
	return (*tokens == TOKEN_REDIRECT_IN || *tokens == TOKEN_REDIRECT_HERE_DOC);
}

static int	is_redirection_out(t_token_type *tokens)
{
	return (*tokens == TOKEN_REDIRECT_OUT
		|| *tokens == TOKEN_REDIRECT_OUT_APPEND);
}

static int	add_redirection(t_redirection **redirections,
		t_redirection *redirection)
{
	t_redirection	*tmp;

	if (!redirection)
		return (0);
	printf("add redirection: %s\n", redirection->file);
	if (!*redirections)
	{
		*redirections = redirection;
		return (1);
	}
	tmp = *redirections;
	printf("added redirection: %s\n", redirection->file);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = redirection;
	return (1);
}

t_ast_node	*parse_command(t_token_type **tokens, char ***instructions)
{
	int			arg_count;
	int			redir_count;
	t_ast_node	*node;
	int			i;

	if (!*tokens || **tokens != TOKEN_COMMAND)
		return (NULL);
	node = ast_new_node(TOKEN_COMMAND);
	arg_count = 0;
	redir_count = 0;
	while ((*tokens)[arg_count] == TOKEN_COMMAND || is_redirection_in(*tokens
			+ arg_count) || is_redirection_out(*tokens + arg_count))
	{
		arg_count++;
		if (is_redirection_in(*tokens + arg_count) || is_redirection_out(*tokens
				+ arg_count))
			redir_count++;
	}
	node->args = gc_calloc(sizeof(char *), (arg_count - (redir_count * 2) + 1));
	i = -1;
	while (++i < arg_count)
	{
		printf("arg: %s\n", **instructions);
		if (is_redirection_in(*tokens))
		{
			if (!add_redirection(&(node->redirections_in),
					parse_redirection(tokens, instructions)))
				return (ast_empty(node));
			++i;
		}
		else if (is_redirection_out(*tokens))
		{
			if (!add_redirection(&(node->redirections_out),
					parse_redirection(tokens, instructions)))
				return (ast_empty(node));
			++i;
		}
		else
		{
			node->args[i] = gc_strdup(**instructions);
			++(*instructions);
			++(*tokens);
		}
	}
	return (node);
}
