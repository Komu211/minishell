/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:31:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 10:56:05 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <libft.h>
# include <unistd.h>
# include "env.h"
# include <stdio.h>

int	builtin_echo(char **args);
int	builtin_env(t_list *env_list);

#endif
