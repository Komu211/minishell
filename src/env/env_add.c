/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:40:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 10:13:53 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_add(t_minishell *mini, char *key, char *value)
{
	t_env	*env;

	env = gc_malloc(sizeof(t_env));
	env->key = gc_strdup(key);
	if (value)
		env->value = gc_strdup(value);
	else
		env->value = NULL;
	ft_lstadd_back(&mini->env_list, gc_lstnew(env));
}
