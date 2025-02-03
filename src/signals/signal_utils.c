/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:23:33 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 16:05:40 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"

void	setup_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	setup_parent_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_parent_handler(t_minishell *mini)
{
	mini->sa.sa_sigaction = parent_handler;
	mini->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mini->sa.sa_mask);
	sigaction(SIGINT, &mini->sa, NULL);
	sigaction(SIGQUIT, &mini->sa, NULL);
}

void	restore_signals(t_minishell *mini)
{
	mini->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mini->sa.sa_mask);
	mini->sa.sa_sigaction = signal_handler;
	sigaction(SIGINT, &mini->sa, NULL);
	sigaction(SIGQUIT, &mini->sa, NULL);
}
