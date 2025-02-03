/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:34:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 10:29:23 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	expand_and_validate_file(t_minishell *mini, char **file)
{
	char	**expanded_split;

	expand_env(mini, file);
	expanded_split = gc_split(*file);
	if (gc_split_size(expanded_split) != 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(*file, 2);
		ft_putendl_fd(": ambiguous redirect", 2);
		gc_split_free(&expanded_split);
		return (-1);
	}
	gc_split_free(&expanded_split);
	remove_quotes(file);
	return (0);
}

static int	expand_redirections(t_minishell *mini, t_ast_node *ast)
{
	t_redirection	*redir;

	redir = ast->redirections_in;
	while (redir)
	{
		if (expand_and_validate_file(mini, &redir->file) == -1)
			return (-1);
		redir = redir->next;
	}
	redir = ast->redirections_out;
	while (redir)
	{
		if (expand_and_validate_file(mini, &redir->file) == -1)
			return (-1);
		redir = redir->next;
	}
	return (0);
}

static int	execute_command_node(t_minishell *mini, t_ast_node *ast)
{
	t_builtin_type	builtin_type;
	int				ret;

	expand_args(mini, &(ast->args));
	builtin_type = is_own_builtin(ast->args[0], ast->args);
	if (builtin_type != BUILTIN_NONE)
		ret = execute_own_builtin(mini, ast, builtin_type);
	else
		ret = execute_external_command(mini, ast);
	return (ret);
}

static int	execute_operator_node(t_minishell *mini, t_ast_node *ast)
{
	int	ret;

	if (ast->type == TOKEN_PIPE)
		ret = execute_pipe(mini, ast);
	else if (ast->type == TOKEN_AND)
		ret = execute_and(mini, ast);
	else if (ast->type == TOKEN_OR)
		ret = execute_or(mini, ast);
	else
		ret = 0;
	return (ret);
}

int	execute_ast(t_minishell *mini, t_ast_node *ast)
{
	t_saved_fds	saved;
	int			ret;

	if (!ast)
		return (0);
	if (expand_redirections(mini, ast) == -1)
		return (mini->exit_status = 1);
	if (handle_redirections(ast, &saved))
		return (mini->exit_status = 1);
	if (ast->type == TOKEN_COMMAND)
		ret = execute_command_node(mini, ast);
	else
		ret = execute_operator_node(mini, ast);
	if (ast->redirections_in || ast->redirections_out)
		reset_fds(&saved);
	mini->exit_status = ret;
	return (ret);
}
