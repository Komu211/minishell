/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:36:19 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 19:51:29 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Include libraries
# include "ast.h"
# include "env.h"
# include "error.h"
# include "garbage_collector.h"
# include "libft.h"
# include "struct.h"
# include "utils.h"
# include "wrapper.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Function prototypes
void	print_welcome(void);
void	cleanup_main(t_minishell *mini);

#endif
