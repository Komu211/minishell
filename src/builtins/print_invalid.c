/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:42:36 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 16:18:51 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

int	print_invalid_identifier(char *cmd, char *arg, t_minishell *mini)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	mini->exit_status = 1;
	return (1);
}

int	print_invalid_option(char *cmd, char *arg, t_minishell *mini)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': invalid option\n", 2);
	mini->exit_status = 2;
	return (2);
}

int	command_not_found(t_minishell *mini, t_ast_node *ast)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(ast->args[0], 2);
	ft_putendl_fd(": command not found", 2);
	mini->exit_status = 127;
	return (127);
}
