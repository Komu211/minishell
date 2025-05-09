/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:57:18 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/30 18:50:14 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

t_heredoc	*apply_heredocs_to_node(t_ast_node *ast, t_heredoc *current_node)
{
	t_redirection	*redir;

	if (!ast || !current_node)
		return (current_node);
	redir = ast->redirections_in;
	while (redir && current_node)
	{
		if (redir->type == REDIRECT_HERE_DOC && !current_node->processed)
		{
			gc_free(redir->file);
			redir->file = gc_strdup(current_node->temp_file);
			redir->type = REDIRECT_IN;
			current_node->processed = 1;
			current_node = current_node->next;
		}
		redir = redir->next;
	}
	return (current_node);
}

void	apply_heredocs_to_ast(t_ast_node *ast, t_heredoc *heredocs)
{
	t_heredoc	*current;

	if (!ast || !heredocs)
		return ;
	current = heredocs;
	apply_heredocs_to_ast(ast->left, current);
	current = heredocs;
	while (current && current->processed)
		current = current->next;
	current = apply_heredocs_to_node(ast, current);
	apply_heredocs_to_ast(ast->right, current);
}
