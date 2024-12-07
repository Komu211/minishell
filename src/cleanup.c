/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:00:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 22:11:06 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_main(t_minishell *mini)
{
	env_empty(&mini->env_list);
	gc_free(mini->hist_file);
	gc_free(mini->pwd);
	garbage_collector_empty();
	ft_putendl_fd("Cleand up and Goodbye!", 1);
}
