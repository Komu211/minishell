/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:53:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 14:32:37 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enums.h"
# include "libft.h"

typedef struct s_ast_node		t_ast_node;
typedef struct s_redirection	t_redirection;

typedef struct s_env
{
	char						*key;
	char						*value;
}								t_env;

typedef struct s_minishell
{
	char						*pwd;
	char						*hist_file;
	int							error;
	int							exit_status;
	t_list						*env_list;
	t_ast_node					*ast;
}								t_minishell;

struct							s_redirection
{
	t_redirection_type			type;
	char						*file;
	t_redirection				*next;
};

struct							s_ast_node
{
	t_token_type				type;
	t_ast_node					*left;
	t_ast_node					*right;
	t_redirection				*redirections_in;
	t_redirection				*redirections_out;
	char						**args;
};

#endif
