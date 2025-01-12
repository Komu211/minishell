/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:53:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 15:22:47 by kmuhlbau         ###   ########.fr       */
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

typedef struct s_saved_fds
{
	int							o_stdin;
	int							o_stdout;
}								t_saved_fds;

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
