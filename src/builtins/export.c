/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:22:00 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/17 01:52:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

int	builtin_export(t_minishell *minishell, t_ast_node *ast)
{
	(void)minishell;
	(void)ast;
	// char	**args;
	// t_env	*env;
	// char	*equals_pos;
	// int		i;
	// args = ast->args;
	// if (!args[1])
	//{
	//	print_sorted_env(minishell->env_list);
	//	return (0);
	//}
	// i = 1;
	// while (args[i])
	//{
	//	equals_pos = ft_strchr(args[i], '=');
	//	if (equals_pos)
	//	{
	//		*equals_pos = '\0';
	//		env = env_find(minishell->env_list, args[i]);
	//		if (env)
	//			env_update(env, equals_pos + 1);
	//		else
	//			env_add(&minishell->env_list, args[i], equals_pos + 1);
	//		*equals_pos = '=';
	//	}
	//	i++;
	//}
	return (0);
}
