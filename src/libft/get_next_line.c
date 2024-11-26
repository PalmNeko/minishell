/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:49:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/21 19:43:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

static char	*gnl_cut(char *buf, size_t *size);
static int	gnl_read_line(int fd, char **buf, size_t *size, size_t *max_size);
static void	gnl_del(t_gnl_node *node);

char	*get_next_line(int fd)
{
	static t_list	*ft_lst;
	t_list			*itr;
	t_gnl_node		*now;
	char			*line;

	errno = 0;
	itr = ft_lst;
	while (itr != NULL && ((t_gnl_node *)(itr->content))->fd != fd)
		itr = itr->next;
	if (itr == NULL)
	{
		now = (t_gnl_node *)malloc(sizeof(t_gnl_node));
		if (now == NULL)
			return (ft_lstclear(&ft_lst, (t_free)gnl_del), NULL);
		*now = (t_gnl_node){.carry_up = NULL, .fd = fd};
		itr = ft_lstnew(now);
		if (itr == NULL || (ft_lstadd_back(&ft_lst, itr), 0))
			return (gnl_del(now), ft_lstclear(&ft_lst, (t_free)gnl_del), NULL);
	}
	now = itr->content;
	line = get_next_line2(fd, &now->carry_up);
	if (line == NULL && itr == ft_lst)
		ft_lst = ft_lst->next;
	return ((line == NULL && (ft_lstdelone(itr, (t_free)gnl_del), 0)),
		(errno != 0 && (ft_lstclear(&ft_lst, (t_free)gnl_del), 0)), line);
}

void	gnl_del(t_gnl_node *node)
{
	if (node == NULL)
		return ;
	free(node->carry_up);
	free(node);
}

/**
 * get_next_line for more security. (less memory leak)
 * @param fd input fd
 * @param carry_up past memory. will overwrite. Please, set to NULL on
 * first read. set NULL if return NULL.
 * @return line string until line. ex. "abc\n" or "abc" when EOF.
 * @exception
 * 	read error.
 *  malloc error.see(read(2), malloc(3))
 */
char	*get_next_line2(int fd, char **carry_up)
{
	int		result;
	size_t	size;
	size_t	max_size;
	char	*line;

	result = 1;
	size = 0;
	if (carry_up == NULL)
		return (NULL);
	while (*carry_up != NULL && (*carry_up)[size] != '\0')
	{
		if ((*carry_up)[size++] == '\n')
			result = 0;
	}
	max_size = size;
	while (result > 0)
		result = gnl_read_line(fd, carry_up, &size, &max_size);
	line = NULL;
	if (result != -1)
		line = gnl_cut(*carry_up, &size);
	if (line == NULL && (free(*carry_up), 1))
		*carry_up = NULL;
	return (line);
}

static char	*gnl_cut(char *buf, size_t *size)
{
	char	*line;
	char	*line_ptr;
	size_t	line_index;
	size_t	cp_len;

	if (*size == 0)
		return (NULL);
	line_ptr = buf;
	line_index = 0;
	while (buf[line_index] != '\n' && line_index < *size - 1)
		line_index++;
	line_ptr = buf + line_index;
	line_index = line_ptr - buf;
	cp_len = line_index + 1;
	line = (char *)malloc(sizeof(char) * (cp_len + 1));
	if (line == NULL)
		return (NULL);
	ft_memmove(line, buf, cp_len);
	line[cp_len] = '\0';
	ft_memmove(buf, line_ptr + 1, (*size - cp_len));
	*size = (*size - cp_len);
	buf[*size] = '\0';
	return (line);
}

static int	gnl_read_line(int fd, char **buf, size_t *size, size_t *max_size)
{
	ssize_t	read_len;
	char	*tmp;

	if (*size + BUFFER_SIZE > *max_size)
	{
		*max_size += BUFFER_SIZE * (*size / BUFFER_SIZE + 1);
		tmp = malloc(sizeof(char) * *max_size);
		if (tmp == NULL)
			return (-1);
		ft_memmove(tmp, *buf, *size);
		free(*buf);
		*buf = tmp;
	}
	read_len = read(fd, *buf + *size, BUFFER_SIZE);
	if (read_len == -1)
		return (-1);
	else if (read_len == 0)
		return (0);
	*size += read_len;
	while (read_len > 0)
	{
		if ((*buf)[*size - read_len--] == '\n')
			return (0);
	}
	return (1);
}
