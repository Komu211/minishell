/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:31:50 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/12 15:38:15 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPER_H
# define WRAPPER_H

# include "error.h"
# include "fd_collector.h"
# include "garbage_collector.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Function prototypes
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t num, size_t size);
void	*gc_realloc(void *ptr, size_t size);
void	gc_free(void *ptr);
char	*gc_getcwd(char *buf);

t_list	*gc_lstnew(void *content);
void	gc_lstclear(t_list **lst, void (*del)(void *));
void	gc_lstdelone(t_list *lst, void (*del)(void *));
void	gc_lstremove(t_list **lst, void *ptr);

int		fdc_open(const char *pathname, int flags);
int		fdc_open_mode(const char *pathname, int flags, int mode);
int		fdc_close(int fd);
int		fdc_pipe(int pipefd[2]);
int		fdc_dup(int oldfd);
int		fdc_dup2(int oldfd, int newfd);

#endif
