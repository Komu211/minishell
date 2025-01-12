/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:30:46 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 10:21:48 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_redirection(t_token_type token)
{
	return (token == TOKEN_REDIRECT_IN || token == TOKEN_REDIRECT_OUT
		|| token == TOKEN_REDIRECT_OUT_APPEND
		|| token == TOKEN_REDIRECT_HERE_DOC);
}
