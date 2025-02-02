/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:47:06 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 12:49:50 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "ast.h"
# include "execution.h"
# include "signal_handler.h"
# include "struct.h"

void	apply_heredocs_to_ast(t_ast_node *ast, t_heredoc *heredocs);
void	read_heredocs(t_heredoc *heredocs);
int		collect_heredocs_from_node(t_ast_node *node, t_heredoc **heredocs,
			int *counter);
void	empty_heredoc(t_heredoc **heredocs);

#endif
