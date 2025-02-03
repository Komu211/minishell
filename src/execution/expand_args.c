/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:25:29 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/03 10:35:23 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	split_again(char ***args)
{
	char	*oneliner;
	char	**new_split;

	oneliner = gc_unsplit(*args);
	new_split = gc_split(oneliner);
	gc_free(oneliner);
	gc_split_free(args);
	*args = new_split;
}

static void	expand_variable(char **line, char **result, t_minishell *mini,
		int quotes)
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
	if (i == 0 && (**line == '\0' || quotes))
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

void	expand_env(t_minishell *mini, char **args)
{
	char		*src;
	char		*result;
	t_quotes	quotes;

	if (!args || !*args)
		return ;
	src = *args;
	result = NULL;
	quotes = (t_quotes){0, 0};
	while (*src)
	{
		if (*src == '\'' && !quotes.in_double)
			quotes.in_single = !quotes.in_single;
		else if (*src == '"' && !quotes.in_single)
			quotes.in_double = !quotes.in_double;
		else if (!quotes.in_single && *src == '$')
		{
			expand_variable(&src, &result, mini, quotes.in_double);
			continue ;
		}
		append_char(&result, *src++);
	}
	gc_free(*args);
	*args = result;
}

void	expand_args(t_minishell *mini, char ***args)
{
	int	i;

	i = -1;
	while ((*args)[++i])
		expand_env(mini, (*args) + i);
	split_again(args);
	expand_wildcards(*args);
	split_again(args);
	i = -1;
	while ((*args)[++i])
		remove_quotes((*args) + i);
}
