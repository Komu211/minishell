/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:45:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/28 18:32:39 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "execution.h"

typedef struct s_heredoc
{
	char *delimiter; // The heredoc delimiter (e.g., "EOF")
	char *temp_file; // Path to temp file that will store content
	struct s_heredoc	*next;
}						t_heredoc;

static void	ft_itoa_to_buf(int n, char *buf)
{
	int		i;
	int		len;
	char	tmp;
	int		start;

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return ;
	}
	i = 0;
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n = n / 10;
	}
	buf[i] = '\0';
	// Reverse the string
	len = i;
	start = 0;
	while (start < len / 2)
	{
		tmp = buf[start];
		buf[start] = buf[len - 1 - start];
		buf[len - 1 - start] = tmp;
		start++;
	}
}

static char	*create_temp_heredoc_file(int *counter)
{
	char	*temp_path;
	char	pid_str[32];
	char	counter_str[32];
	int		fd;

	ft_itoa_to_buf(getpid(), pid_str);
	ft_itoa_to_buf(*counter, counter_str);
	temp_path = gc_calloc(1, ft_strlen("/tmp/.heredoc_") + ft_strlen(pid_str)
			+ ft_strlen(counter_str) + 2);
	if (!temp_path)
		return (NULL);
	ft_strlcpy(temp_path, "/tmp/.heredoc_", ft_strlen("/tmp/.heredoc_") + 1);
	ft_strlcat(temp_path, pid_str, ft_strlen(temp_path) + ft_strlen(pid_str) + 1);
	ft_strlcat(temp_path, "_", ft_strlen(temp_path) + 2);
	ft_strlcat(temp_path, counter_str, ft_strlen(temp_path)
		+ ft_strlen(counter_str) + 1);
	(*counter)++;
	fd = open(temp_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		gc_free(temp_path);
		return (NULL);
	}
	close(fd);
	return (temp_path);
}

void	collect_heredocs_from_node(t_ast_node *node, t_heredoc **heredocs,
		int *counter)
{
	t_redirection	*redir;
	t_heredoc		*new_heredoc;

	if (!node)
		return ;
	redir = node->redirections_in;
	while (redir)
	{
		if (redir->type == REDIRECT_HERE_DOC)
		{
			new_heredoc = gc_calloc(1, sizeof(t_heredoc));
			new_heredoc->delimiter = gc_strdup(redir->file);
			new_heredoc->temp_file = create_temp_heredoc_file(counter);
			if (!new_heredoc->temp_file)
			{
				// Handle error
				return ;
			}
			new_heredoc->next = *heredocs;
			*heredocs = new_heredoc;
		}
		redir = redir->next;
	}
	collect_heredocs_from_node(node->left, heredocs, counter);
	collect_heredocs_from_node(node->right, heredocs, counter);
}
