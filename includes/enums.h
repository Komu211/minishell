/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:48:07 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 18:48:31 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_token_type
{
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_PIPE,
	TOKEN_PARAN_OPEN,
	TOKEN_PARAN_CLOSE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_COMMAND
}					t_token_type;

#endif