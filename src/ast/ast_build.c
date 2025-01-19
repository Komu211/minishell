/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:19:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 12:34:22 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*ast_build(t_token_type *tokens, char **split_line,
		t_minishell *mini)
{
	t_ast_node	*node;

	if (!tokens)
		return (NULL);
	node = parse_logical_ops(&tokens, &split_line);
	if (!node || *tokens != TOKEN_EMPTY)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		if (*split_line)
			ft_putstr_fd(*split_line, 2);
		ft_putstr_fd("'\n", 2);
		mini->exit_status = 2;
		return (ast_empty(node));
	}
	return (node);
}
