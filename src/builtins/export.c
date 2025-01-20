/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:22:00 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 18:54:54 by kmuhlbau         ###   ########.fr       */
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

static int	handle_single_export(t_minishell *minishell, char *arg)
{
	char	**split;
	char	*equals_pos;

	equals_pos = ft_strchr(arg, '=');
	if (equals_pos)
	{
		split = gc_split_at(arg, '=');
		if (!split || !split[0])
			return (gc_split_free(&split),
				error_handler("Invalid export format", 1), 1);
		if (!check_only_valid_chars(split[0]))
			return (gc_split_free(&split),
				error_handler("Invalid export format", 1), 1);
		if (equals_pos[1] == '\0')
			env_set(minishell, split[0], "");
		else
			env_set(minishell, split[0], split[1]);
		gc_split_free(&split);
	}
	else
		env_add(minishell, arg, NULL);
	return (0);
}

int	builtin_export(t_minishell *minishell, char **args)
{
	int	i;
	int	status;

	if (!args[1])
		print_declare_export(minishell->env_list);
	else
	{
		status = 0;
		i = 1;
		while (args[i])
		{
			if (!ft_strchr(args[i], '=') && get_env_value(args[i],
					minishell->env_list))
			{
				i++;
				continue ;
			}
			if (handle_single_export(minishell, args[i]) != 0)
				status = 1;
			else
				status = 0;
			i++;
		}
		return (status);
	}
	return (0);
}
