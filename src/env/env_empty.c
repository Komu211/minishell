/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:33:08 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 17:42:33 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

void	env_destroy(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	gc_free(env->key);
	gc_free(env->value);
	gc_free(env);
}

void	env_empty(t_list **env_list)
{
	gc_lstclear(env_list, env_destroy);
}
