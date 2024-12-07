/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:30:06 by obehavka          #+#    #+#             */
/*   Updated: 2024/12/07 22:11:00 by kmuhlbau         ###   ########.fr       */
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

#endif
