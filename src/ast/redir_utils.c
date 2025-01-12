/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:47:16 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 12:30:57 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	add_redirection(t_redirection **redirections,
		t_redirection *redirection)
{
	t_redirection	*tmp;

	printf("add redirection: %s\n", redirection->file);
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
