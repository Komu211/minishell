/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:42:45 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 12:56:59 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

static int	is_invalid_var_name(char *name)
{
	if (!*name)
		return (1);
	if (ft_isdigit(name[0]))
		return (1);
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (1);
		name++;
	}
	return (0);
}

static void	remove_env_var(t_minishell *minishell, char *key)
{
	t_list	*current;
	t_list	*prev;
	t_env	*env;

	current = minishell->env_list;
	prev = NULL;
	while (current)
	{
		env = (t_env *)current->content;
		if (ft_strcmp(env->key, key) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				minishell->env_list = current->next;
			gc_lstdelone(current, env_destroy);
			break ;
		}
		prev = current;
		current = current->next;
	}
}

int	builtin_unset(t_minishell *minishell, t_ast_node *ast)
{
	int		i;
	int		status;
	char	**args;

	args = ast->args;
	if (!args || !args[1])
		return (0);
	status = 0;
	i = 1;
	while (args[i])
	{
		if (args[i][0] == '-')
			status = print_invalid_option("unset", args[i], minishell);
		else if (is_invalid_var_name(args[i]))
			status = print_invalid_identifier("unset", args[i], minishell);
		else
			remove_env_var(minishell, args[i]);
		i++;
	}
	return (status);
}
