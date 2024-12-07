/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:31:50 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 16:45:10 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPER_H
# define WRAPPER_H

# include "error.h"
# include "garbage_collector.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Function prototypes
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t num, size_t size);
void	*gc_realloc(void *ptr, size_t size);
void	gc_free(void *ptr);
char	*gc_getcwd(char *buf);

#endif
