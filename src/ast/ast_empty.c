/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:16:06 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 20:26:44 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	*ast_empty(t_ast_node *node)
{
	int	i;

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
		gc_free(node);
	}
	return (NULL);
}
