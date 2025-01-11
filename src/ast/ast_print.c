/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:07:27 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 15:55:49 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// Lookup table for token types
static const char	*g_token_names[] = {[TOKEN_AND] = "AND", [TOKEN_OR] = "OR",
		[TOKEN_PIPE] = "PIPE", [TOKEN_PAREN_OPEN] = "(",
		[TOKEN_PAREN_CLOSE] = ")", [TOKEN_REDIRECT_IN] = "<",
		[TOKEN_REDIRECT_OUT] = ">", [TOKEN_COMMAND] = "CMD"};

static void	print_indent(int level)
{
	for (int i = 0; i < level * 4; i++)
		printf(" ");
}

static void	print_redirection(t_redirection *redirection)
{
	if (redirection->type == REDIRECT_IN)
		printf(" < [ %s ]", redirection->file);
	else if (redirection->type == REDIRECT_OUT)
		printf(" > [ %s ]", redirection->file);
	else if (redirection->type == REDIRECT_OUT_APPEND)
		printf(" >> [ %s ]", redirection->file);
	else if (redirection->type == REDIRECT_HERE_DOC)
		printf(" << [ %s ]", redirection->file);
	if (redirection->next)
	{
		printf(" ");
		print_redirection(redirection->next);
	}
}

static void	print_command_args(char **args)
{
	if (!args)
		return ;
	printf("[ ");
	for (int i = 0; args[i]; i++)
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	printf(" ]");
}

void	print_ast(t_ast_node *node, int level)
{
	if (!node)
		return ;
	print_indent(level);
	printf("├── %s", g_token_names[node->type]);
	if (node->type == TOKEN_COMMAND && node->args)
	{
		printf(" ");
		print_command_args(node->args);
	}
	if (node->redirections_in)
		print_redirection(node->redirections_in);
	if (node->redirections_out)
		print_redirection(node->redirections_out);
	printf("\n");
	if (node->left)
		print_ast(node->left, level + 1);
	if (node->right)
		print_ast(node->right, level + 1);
}

// Debug function to visualize the AST
void	debug_ast(t_ast_node *root)
{
	printf("\n=== AST DEBUG VIEW ===\n");
	if (!root)
		printf("(empty tree)\n");
	else
		print_ast(root, 0);
	printf("====================\n\n");
}

// Test function to verify AST construction
void	test_ast_construction(void)
{
	t_ast_node	*cmd;
	t_ast_node	*pipe;

	// Test 1: Simple command
	printf("Test 1: Simple command 'ls -l'\n");
	cmd = ast_new_node(TOKEN_COMMAND);
	cmd->args = gc_calloc(sizeof(char *), 3);
	cmd->args[0] = gc_strdup("ls");
	cmd->args[1] = gc_strdup("-l");
	debug_ast(cmd);
	ast_empty(cmd);
	// Test 2: Pipe command
	printf("Test 2: Pipe 'ls -l | grep test'\n");
	pipe = ast_new_node(TOKEN_PIPE);
	pipe->left = ast_new_node(TOKEN_COMMAND);
	pipe->left->args = gc_calloc(sizeof(char *), 3);
	pipe->left->args[0] = gc_strdup("ls");
	pipe->left->args[1] = gc_strdup("-l");
	pipe->right = ast_new_node(TOKEN_COMMAND);
	pipe->right->args = gc_calloc(sizeof(char *), 3);
	pipe->right->args[0] = gc_strdup("grep");
	pipe->right->args[1] = gc_strdup("test");
	debug_ast(pipe);
	ast_empty(pipe);
}
