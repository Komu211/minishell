/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:19:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 17:40:16 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

static void	verify_env(t_minishell *mini)
{
	t_list	*tmp;
	t_env	*env;
	int		shlvl;
	char	*pwd;

	tmp = mini->env_list;
	shlvl = -1;
	pwd = NULL;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		if (ft_strcmp(env->key, "SHLVL") == 0)
			shlvl = ft_atoi(env->value);
		if (ft_strcmp(env->key, "PWD") == 0)
			pwd = env->value;
		tmp = tmp->next;
	}
	if (shlvl == -1)
		env_add(mini, "SHLVL", "1");
	else
		env_set(mini, "SHLVL", gc_itoa(shlvl + 1));
	if (pwd == NULL)
		env_add(mini, "PWD", mini->pwd);
}

void	env_init(t_minishell *mini, char **envp)
{
	int		i;
	int		j;
	t_env	*env;
	t_list	*tmp;

	i = -1;
	mini->env_list_orig = envp;
	mini->env_list = NULL;
	while (envp[++i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		env = gc_malloc(sizeof(t_env));
		env->key = gc_calloc(j + 1, 1);
		ft_memcpy(env->key, envp[i], j);
		env->value = gc_strdup(envp[i] + j + 1);
		tmp = gc_lstnew(env);
		ft_lstadd_back(&mini->env_list, tmp);
	}
	verify_env(mini);
}
