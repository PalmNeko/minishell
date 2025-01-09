/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_aligned_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:23:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 16:05:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_write_aligned_left(int fd, const void *buf, size_t n, size_t width)
{
	ssize_t	write_len;
	ssize_t	tmp_len;

	write_len = 0;
	tmp_len = write(fd, buf, n);
	if (tmp_len == -1)
		return (-1);
	write_len += tmp_len;
	while (write_len >= 0 && write_len < (ssize_t)width)
	{
		tmp_len = write(fd, " ", 1);
		if (tmp_len == -1)
			return (-1);
		write_len += tmp_len;
	}
	if (write_len < 0)
		return (-1);
	return (write_len);
}
