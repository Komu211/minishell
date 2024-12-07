/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:53:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 16:14:01 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

typedef struct s_minishell
{
    char    *pwd;
    char    *hist_file;
    int     error;
    int     exit_status;
    t_list  *env_list;
}           t_minishell;

#endif