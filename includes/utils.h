/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:19:43 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 19:36:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "wrapper.h"

void	*gc_strdup(const char *s);
char	*gc_strjoin(char const *s1, char const *s2);
char	*gc_substr(char const *s, unsigned int start, size_t len);
char	**gc_split(char const *s);

#endif
