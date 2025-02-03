/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:22:00 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 10:40:22 by obehavka         ###   ########.fr       */
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
	if (!str)
		return (0);
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_isdigit(str[0]))
		return (0);
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
	char	*equals_pos;
	char	*key;
	char	*value;

	equals_pos = ft_strchr(arg, '=');
	if (arg[0] == '-')
		return (print_invalid_option("export", arg, minishell));
	if (equals_pos)
	{
		key = gc_substr(arg, 0, equals_pos - arg);
		if (!key || !check_only_valid_chars(key))
			return (gc_free(key), print_invalid_identifier("export", arg,
					minishell), 1);
		value = gc_strdup(equals_pos + 1);
		env_set(minishell, key, value);
		gc_free(key);
		gc_free(value);
	}
	else
	{
		if (!check_only_valid_chars(arg))
			return (print_invalid_identifier("export", arg, minishell), 1);
		env_add(minishell, arg, NULL);
	}
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
			status = handle_single_export(minishell, args[i]);
			i++;
		}
		return (status);
	}
	return (0);
}
