/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:31:50 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 11:57:48 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "libft.h"
# include "error.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Function prototypes
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t num, size_t size);
void	*gc_realloc(void *ptr, size_t size);
void	gc_free(void *ptr);

#endif
