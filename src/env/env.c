/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:19:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 16:14:16 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

void	env_init(t_minishell *mini, char **envp)
{
	int		i;
	int		j;
	t_env	*env;
	t_list	*tmp;

	i = 0;
	mini->env_list = NULL;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		env = gc_malloc(sizeof(t_env));
		env->key = gc_calloc(j + 1, 1);
		ft_memcpy(env->key, envp[i], j);
		env->value = gc_strdup(envp[i] + j + 1);
		tmp = ft_lstnew(env);
		if (!tmp)
			error_handler("ft_lstnew failed", 1);
		ft_lstadd_back(&mini->env_list, tmp);
		i++;
	}
}
