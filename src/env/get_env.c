/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:17:39 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/18 09:17:46 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

const char	*get_env_value(char *key, t_list *env_list)
{
	t_env	*env;

	while (env_list)
	{
		env = (t_env *)env_list->content;
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env_list = env_list->next;
	}
	return (NULL);
}
