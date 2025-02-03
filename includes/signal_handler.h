/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:15:12 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 16:17:35 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include "minishell.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>

void	signal_setup(t_minishell *mini);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	setup_child_signals(void);
void	restore_signals(t_minishell *mini);
void	setup_heredoc_handler(t_minishell *mini);
void	parent_handler(int signum, siginfo_t *info, void *context);
void	setup_parent_handler(t_minishell *mini);
void	parent_ignore_signals(void);
void	heredoc_signal_handler(int signum, siginfo_t *info, void *context);

#endif
