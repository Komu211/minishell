/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:48:07 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 13:31:35 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_token_type
{
	TOKEN_EMPTY,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_PIPE,
	TOKEN_PAREN_OPEN,
	TOKEN_PAREN_CLOSE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_OUT_APPEND,
	TOKEN_REDIRECT_HERE_DOC,
	TOKEN_COMMAND
}	t_token_type;

typedef enum e_redirection_type
{
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	REDIRECT_HERE_DOC
}	t_redirection_type;

#endif
