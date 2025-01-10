/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:18:25 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 16:25:52 by kmuhlbau         ###   ########.fr       */
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
