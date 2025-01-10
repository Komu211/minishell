/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:31:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 17:41:49 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <libft.h>
# include <unistd.h>
#include "env.h"

int	builtin_echo(char **args);
int	builtin_env(t_list *env_list);

#endif
