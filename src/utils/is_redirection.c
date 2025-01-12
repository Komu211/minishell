/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:14:41 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 12:40:36 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_redirection_in(t_token_type tokens)
{
	return (tokens == TOKEN_REDIRECT_IN || tokens == TOKEN_REDIRECT_HERE_DOC);
}

int	is_redirection_out(t_token_type tokens)
{
	return (tokens == TOKEN_REDIRECT_OUT
		|| tokens == TOKEN_REDIRECT_OUT_APPEND);
}

int	is_redirection(t_token_type tokens)
{
	return (is_redirection_in(tokens) || is_redirection_out(tokens));
}
