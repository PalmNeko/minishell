/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:56:59 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 18:14:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[10];
	int		size;
	int		index;

	if (n < 0)
		write(fd, "-", 1);
	else if (n > 0)
		n *= -1;
	else if (n == 0)
		write(fd, "0", 1);
	size = sizeof(buf) / sizeof(buf[0]);
	index = size - 1;
	while (n != 0)
	{
		buf[index] = '0' + (-1 * (n % 10));
		n /= 10;
		index--;
	}
	index += 1;
	write(fd, buf + index, size - index);
	return ;
}
