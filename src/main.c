/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:06:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 16:28:35 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome(void)
{
	ft_putstr_fd("\033[1;36m", 1); // Bright cyan color
	ft_putendl_fd("┌──────────────────────────────────────────────────────┐",
		1);
	ft_putendl_fd("│    ____  __ __                  _____ __         ____│",
		1);
	ft_putendl_fd("│   / __ \\/ //_/__  ____ ___  __ / ___// /_  ___  / / /│",
		1);
	ft_putendl_fd("│  / / / / ,< / _ \\/ __ `/ / / / \\__ \\/ __ \\/ _ \\/ / "
					"/ │",
					1);
	ft_putendl_fd("│ / /_/ / /| /  __/ /_/ / /_/ / ___/ / / / /  __/ / /  │",
		1);
	ft_putendl_fd("│ \\____/_/ |_\\___/\\__,_/\\__, / /____/_/ /_/\\___/_/_"
					"/   │",
					1);
	ft_putendl_fd("│                      /____/                          │",
		1);
	ft_putendl_fd("└──────────────────────────────────────────────────────┘",
		1);
	ft_putstr_fd("\033[0m\n", 1);
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
		if (*user_in) // Only process non-empty input
		{
			ast_init(&mini.ast, user_in);
			if (mini.ast)
			{
				printf("\nCommand entered: %s\n", user_in);
				debug_ast(mini.ast);
				execute_ast(&mini, mini.ast);
				// Free previous AST before next iteration
				mini.ast = ast_empty(mini.ast);
			}
			add_history(user_in); // Add command to readline history
		}
		free(user_in); // readline allocated memory needs to be freed
		gc_free(prompt);
	}
	cleanup_main(&mini);
	return (0);
}
