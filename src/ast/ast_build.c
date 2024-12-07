/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:19:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:49:44 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*ast_build(t_token_type *tokens, char **split_line)
{
	(void)tokens;
	(void)split_line;
	printf("ast_build\n");
	return (NULL);
	// if (!tokens)
	//     return (NULL);
	// return (parse_logical_ops(&tokens));
}
