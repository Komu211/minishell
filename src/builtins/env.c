/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:36:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 13:41:22 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

int	builtin_env(t_list *env_list)
{
	t_env	*env;

	while (env_list)
	{
		env = (t_env *)env_list->content;
		env_list = env_list->next;
		if (env->value && env->value[0] != '\0')
			printf("%s=%s\n", env->key, env->value);
		else if (env->value)
			printf("%s=%c%c\n", env->key, '\"', '\"');
	}
	return (0);
}
