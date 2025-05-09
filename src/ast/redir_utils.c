/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:47:16 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 17:32:11 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	add_redirection(t_redirection **redirections,
		t_redirection *redirection)
{
	t_redirection	*tmp;

	if (!*redirections)
	{
		*redirections = redirection;
		return ;
	}
	tmp = *redirections;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = redirection;
}

int	count_arguments(t_token_type *tokens)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (tokens[i] && (tokens[i] == TOKEN_COMMAND
			|| is_redirection(tokens[i])))
	{
		if (tokens[i] == TOKEN_COMMAND)
			count++;
		else
		{
			i++;
			if (tokens[i] != TOKEN_COMMAND)
				return (count + 2);
		}
		i++;
	}
	if (!count)
		return (2);
	return (count + 1);
}
