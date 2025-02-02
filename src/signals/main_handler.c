/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:08:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 13:07:14 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGINT)
	{
		(*get_mini())->exit_status = 1;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}

void	signal_setup(t_minishell *mini)
{
	mini->sa.sa_sigaction = signal_handler;
	mini->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mini->sa.sa_mask);
	if (isatty(STDIN_FILENO))
	{
		sigaction(SIGINT, &mini->sa, NULL);
		sigaction(SIGQUIT, &mini->sa, NULL);
		rl_catch_signals = 0;
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

static void	heredoc_signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGINT)
	{
		(*get_mini())->heredoc_interrupted = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}

void	setup_heredoc_handler(t_minishell *mini)
{
	mini->sa.sa_sigaction = heredoc_signal_handler;
	mini->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mini->sa.sa_mask);
	sigaction(SIGINT, &mini->sa, NULL);
	sigaction(SIGQUIT, &mini->sa, NULL);
}
