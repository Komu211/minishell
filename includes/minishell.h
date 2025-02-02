/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:36:19 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/02 17:40:17 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Include libraries
# include "ast.h"
# include "env.h"
# include "error.h"
# include "execution.h"
# include "fd_collector.h"
# include "garbage_collector.h"
# include "heredoc.h"
# include "libft.h"
# include "signal_handler.h"
# include "struct.h"
# include "utils.h"
# include "wrapper.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Function prototypes
void	print_welcome(void);
void	cleanup_main(t_minishell *mini);
void	mini_init(char **envp, t_minishell **mini, int argc, char **argv);

#endif
