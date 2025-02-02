/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:16:06 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 17:45:26 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		gc_free(args[i++]);
	gc_free(args);
}

static void	free_redirections(t_redirection *redir)
{
	t_redirection	*tmp;

	while (redir)
	{
		gc_free(redir->file);
		tmp = redir->next;
		gc_free(redir);
		redir = tmp;
	}
}

void	*ast_empty(t_ast_node *node)
{
	if (!node)
		return (NULL);
	if (node->left)
		ast_empty(node->left);
	if (node->right)
		ast_empty(node->right);
	if (node->args)
		free_args(node->args);
	free_redirections(node->redirections_in);
	free_redirections(node->redirections_out);
	gc_free(node);
	return (NULL);
}
