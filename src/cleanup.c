/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:00:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 10:44:13 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_main(t_minishell *mini)
{
	int	tmp;

	tmp = mini->exit_status;
	env_empty(&mini->env_list);
	gc_free(mini->hist_file);
	gc_free(mini->pwd);
	fd_collector_empty();
	garbage_collector_empty();
	exit(tmp);
}
