/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:16:06 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 15:54:46 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	*ast_empty(t_ast_node *node)
{
	int				i;
	t_redirection	*redirection_in;
	t_redirection	*redirection_out;
	t_redirection	*tmp;

	i = 0;
	if (node)
	{
		if (node->left)
			ast_empty(node->left);
		if (node->right)
			ast_empty(node->right);
		if (node->args)
		{
			while (node->args[i])
				gc_free(node->args[i++]);
			gc_free(node->args);
		}
		redirection_in = node->redirections_in;
		while (redirection_in)
		{
			gc_free(redirection_in->file);
			tmp = redirection_in->next;
			gc_free(redirection_in);
			redirection_in = tmp;
		}
		redirection_out = node->redirections_out;
		while (redirection_out)
		{
			gc_free(redirection_out->file);
			tmp = redirection_out->next;
			gc_free(redirection_out);
			redirection_out = tmp;
		}
		gc_free(node);
	}
	return (NULL);
}
