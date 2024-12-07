/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:53:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:50:57 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enums.h"
# include "libft.h"

typedef struct s_ast_node	t_ast_node;

typedef struct s_env
{
	char					*key;
	char					*value;
}							t_env;

typedef struct s_minishell
{
	char					*pwd;
	char					*hist_file;
	int						error;
	int						exit_status;
	t_list					*env_list;
	t_ast_node				*ast;
}							t_minishell;

struct						s_ast_node
{
	t_token_type			type;
	t_ast_node				*left;
	t_ast_node				*right;
	char					**args;
};

#endif