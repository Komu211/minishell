/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:18:25 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 10:56:21 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include "struct.h"

// Function headers
void	env_init(t_minishell *mini, char **envp);
void	env_destroy(void *env);
void	env_empty(t_list **env);
char	*get_env_value(char *key, t_list *env_list);

#endif
