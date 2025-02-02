/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:30:06 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/02 12:24:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# define GC_SIZE 20

# include "error.h"
# include "libft.h"

t_list	**garbage_holder(void);
void	garbage_collector_add(void *ptr);
int		garbage_collector_remove(void *ptr);
void	garbage_collector_empty(void);
size_t	garbage_collector_size(void);
void	garbage_collector_print(void);

#endif
