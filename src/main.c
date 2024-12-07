/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:06:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:51:08 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome(void)
{
	printf("Welcome to the OKeay Shell!\n\n");
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

// void	print_envs(t_list *env_list)
// {
// 	t_list	*tmp;
// 	t_env	*envs;

// 	tmp = env_list;
// 	while (tmp)
// 	{
// 		envs = (t_env *)tmp->content;
// 		printf("%s: %s\n", envs->key, envs->value);
// 		tmp = tmp->next;
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	t_minishell	mini;
	char		*user_in;
	char		*prompt;

	print_welcome();
	mini_init(argc, argv, envp, &mini);
	while (1)
	{
		prompt = gc_strjoin(mini.pwd, " > ");
		user_in = readline(prompt);
		if (!user_in)
			break ;
		ast_init(&mini.ast, user_in);
		gc_free(prompt);
	}
	cleanup_main(&mini);
	return (0);
}
