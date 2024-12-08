/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:15:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/08 14:25:58 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "enums.h"
# include "libft.h"
# include "struct.h"
# include "utils.h"
# include "wrapper.h"

# define SPECIAL_TOKENS "()<>|"

// Function prototypes
t_ast_node	*ast_new_node(t_token_type type);
void		ast_init(t_ast_node **node, char *line);
void		*ast_empty(t_ast_node *node);
t_ast_node	*ast_build(t_token_type *tokens, char **split_line);
t_ast_node	*parse_logical_ops(t_token_type **tokens, char ***instructions);
t_ast_node	*parse_pipe(t_token_type **tokens, char ***instructions);
t_ast_node	*parse_parentheses(t_token_type **tokens, char ***instructions);
t_ast_node	*parse_command(t_token_type **tokens, char ***instructions);
void		test_ast_construction(void);
void		debug_ast(t_ast_node *root);
void		print_ast(t_ast_node *node, int level);
#endif
