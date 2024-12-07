/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:15:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:49:11 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "enums.h"
# include "libft.h"
# include "struct.h"
# include "utils.h"
# include "wrapper.h"

// Function prototypes
t_ast_node	*ast_new_node(t_token_type type);
void		ast_init(t_ast_node **node, char *line);
t_ast_node	*ast_build(t_token_type *tokens, char **split_line);

#endif
