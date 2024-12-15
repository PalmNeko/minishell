/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_aligned_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:23:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 14:01:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_write_aligned_right(int fd, const void *buf, size_t n, size_t width)
{
	ssize_t	write_len;
	ssize_t	tmp_len;
	size_t	space_len;

	if (n < width)
		space_len = width - n;
	else
		space_len = 0;
	write_len = 0;
	while (write_len >= 0 && write_len < (ssize_t)space_len)
	{
		tmp_len = write(fd, " ", 1);
		if (tmp_len == -1)
			return (-1);
		write_len += tmp_len;
	}
	if (write_len < 0)
		return (-1);
	tmp_len = write(fd, buf, n);
	if (tmp_len == -1)
		return (-1);
	write_len += tmp_len;
	return (write_len);
}
