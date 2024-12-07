/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:06:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 16:57:22 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome(void)
{
	printf("Welcome to minishell!\n");
}

void	mini_init(int argc, char **argv, char **envp, t_minishell *mini)
{
	mini->pwd = gc_getcwd(NULL);
	if (!mini->pwd)
		error_handler("getcwd failed", 1);
	mini->hist_file = gc_strjoin(mini->pwd, "/.minishell_history");
	if (!mini->hist_file)
		error_handler("ft_strjoin failed", 1);
	env_init(mini, envp);
	if (!mini->env_list)
		error_handler("ft_strdup_array failed", 1);
	mini->error = 0;
	mini->exit_status = 0;
	(void)argc;
	(void)argv;
}

void	print_envs(t_list *env_list)
{
	t_list	*tmp;
	t_env	*envs;

	tmp = env_list;
	while (tmp)
	{
		envs = (t_env *)tmp->content;
		printf("%s: %s\n", envs->key, envs->value);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	mini;

	print_welcome();
	mini_init(argc, argv, envp, &mini);
	print_envs(mini.env_list);
	env_empty(&mini.env_list);
	ft_putendl_fd("env_list is empty\n", 1);
	gc_free(mini.hist_file);
	gc_free(mini.pwd);
	return (0);
}
