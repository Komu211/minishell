/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setups.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:11:06 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 16:34:06 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"

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
	mini->sa.sa_sigaction = regular_signal_handler;
	mini->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mini->sa.sa_mask);
	if (isatty(STDIN_FILENO))
	{
		sigaction(SIGINT, &mini->sa, NULL);
		sigaction(SIGQUIT, &mini->sa, NULL);
		sigaction(SIGTSTP, &mini->sa, NULL);
		rl_catch_signals = 0;
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
	}
}

void	signal_setup(t_minishell *mini)
{
	restore_signals(mini);
}

void	setup_heredoc_handler(t_minishell *mini)
{
	mini->sa.sa_sigaction = heredoc_signal_handler;
	mini->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mini->sa.sa_mask);
	sigaction(SIGINT, &mini->sa, NULL);
	sigaction(SIGQUIT, &mini->sa, NULL);
}
