/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/19 11:16:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include "enums.h"
# include "struct.h"
# include "wrapper.h"

void	*gc_strdup(const char *s);
char	*gc_strjoin(char const *s1, char const *s2);
char	*gc_substr(char const *s, unsigned int start, size_t len);
char	**gc_split(char const *s);
char	**gc_split_at(char const *s, char c);
void	gc_split_free(char ***split);
int		is_redirection_in(t_token_type tokens);
int		is_redirection_out(t_token_type tokens);
int		is_redirection(t_token_type tokens);
char	*gc_itoa(int n);
void	append_char(char **dest, char c);
void	append_string(char **dest, const char *src);
char	*gc_unsplit(char **split);
int		gc_split_size(char **split);

#endif
