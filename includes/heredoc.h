/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:47:06 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 12:50:37 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "ast.h"
# include "execution.h"
# include "signal_handler.h"

typedef struct s_heredoc
{
	char				*delimiter;
	char				*temp_file;
	struct s_heredoc	*next;
	int					processed;
}						t_heredoc;

void					apply_heredocs_to_ast(t_ast_node *ast,
							t_heredoc *heredocs);
int						read_heredocs(t_heredoc *heredocs, t_minishell *mini);
int						collect_heredocs_from_node(t_ast_node *node,
							t_heredoc **heredocs, int *counter);

#endif
