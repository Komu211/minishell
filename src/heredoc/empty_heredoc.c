/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:48:37 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/02 13:30:19 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

void	empty_heredoc(t_heredoc **heredocs)
{
	t_heredoc	*current;
	t_heredoc	*next;

	if (!heredocs || !*heredocs)
		return ;
	current = *heredocs;
	while (current)
	{
		next = current->next;
		unlink(current->temp_file);
		gc_free(current->temp_file);
		gc_free(current->delimiter);
		gc_free(current);
		current = next;
	}
	*heredocs = NULL;
}
