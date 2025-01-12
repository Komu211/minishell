/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:00:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 15:54:09 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_main(t_minishell *mini)
{
	env_empty(&mini->env_list);
	gc_free(mini->hist_file);
	gc_free(mini->pwd);
	fd_collector_empty();
	garbage_collector_empty();
}
