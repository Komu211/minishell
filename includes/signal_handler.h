/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:15:12 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 12:33:05 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include "minishell.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void	signal_setup(t_minishell *mini);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	setup_child_signals(void);
void	setup_parent_signals(void);
void	restore_signals(t_minishell *mini);

#endif
