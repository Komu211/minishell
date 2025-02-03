/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:42:59 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 13:18:39 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	expand_variable(char **line, char **result, t_minishell *mini)
{
	int			i;
	char		var_name[256];
	const char	*expanded;

	i = 0;
	(*line)++;
	if (*line && **line == '?')
	{
		(*line)++;
		append_string(result, ft_itoa(mini->exit_status));
		return ;
	}
	while (**line && (ft_isalnum(**line) || **line == '_') && i < 255)
		var_name[i++] = *(*line)++;
	var_name[i] = '\0';
	if (i == 0)
	{
		append_char(result, '$');
		return ;
	}
	expanded = get_env_value(var_name, mini->env_list);
	if (expanded)
		append_string(result, expanded);
	else
		append_string(result, "");
}

static void	expand_env_heredoc(t_minishell *mini, char **args)
{
	char	*src;
	char	*result;

	if (!args || !*args)
		return ;
	src = *args;
	result = gc_strdup("");
	while (*src)
	{
		if (*src == '$')
			expand_variable(&src, &result, mini);
		else
			append_char(&result, *src++);
	}
	gc_free(*args);
	*args = result;
}

static void	read_single_heredoc(t_heredoc *current, t_minishell *mini,
		int had_quotes)
{
	int		fd;
	char	*user_in;

	fd = fdc_open_mode(current->temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	while (!mini->heredoc_interrupted)
	{
		user_in = get_user_input("heredoc> ");
		if (!user_in)
			break ;
		garbage_collector_add(user_in);
		if (ft_strcmp(user_in, current->delimiter) == 0)
		{
			gc_free(user_in);
			break ;
		}
		if (!had_quotes)
			expand_env_heredoc(mini, &user_in);
		write(fd, user_in, ft_strlen(user_in));
		write(fd, "\n", 1);
		gc_free(user_in);
	}
	fdc_close(fd);
}

int	read_heredocs(t_heredoc *heredocs, t_minishell *mini)
{
	t_heredoc	*current;
	int			had_quotes;

	if (!heredocs)
		return (1);
	current = heredocs;
	mini->heredoc_interrupted = 0;
	setup_parent_signals();
	setup_heredoc_handler(mini);
	while (current)
	{
		had_quotes = remove_quotes(&current->delimiter);
		read_single_heredoc(current, mini, had_quotes);
		if (mini->heredoc_interrupted)
			break ;
		current = current->next;
	}
	restore_signals(mini);
	mini->exit_status = mini->heredoc_interrupted;
	return (!mini->heredoc_interrupted);
}
