/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:22:00 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 10:00:58 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

static void	print_declare_export(t_list *env_list)
{
	t_env	*env;
	t_list	*tmp;

	tmp = env_list;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		tmp = tmp->next;
		if (env->value)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else
			printf("declare -x %s\n", env->key);
	}
}

static int	check_only_valid_chars(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

int	builtin_export(t_minishell *minishell, char **args)
{
	char	**split;

	if (!args[1])
		print_declare_export(minishell->env_list);
	else
	{
		if (ft_strchr(args[1], '='))
		{
			split = gc_split_at(args[1], '=');
			if (!split || !split[0] || !split[1])
			{
				gc_split_free(&split);
				return (error_handler("Invalid export format", 1), 1);
			}
			if (!check_only_valid_chars(split[0]))
			{
				gc_split_free(&split);
				return (error_handler("Invalid export format", 1), 1);
			}
			env_set(minishell, split[0], split[1]);
			gc_split_free(&split);
		}
		else
			env_add(minishell, args[1], NULL);
	}
	return (0);
}
