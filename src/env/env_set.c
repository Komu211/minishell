/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:54:18 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 10:01:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_set(t_minishell *mini, char *key, char *value)
{
	t_env	*env;
	t_list	*tmp;

	tmp = mini->env_list;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		if (ft_strcmp(env->key, key) == 0)
		{
			gc_free(env->value);
			env->value = gc_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	env_add(mini, key, value);
}
