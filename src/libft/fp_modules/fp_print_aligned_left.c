/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_print_aligned_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:20:09 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 15:10:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

int	fp_print_aligned_left(int fd, int field_width, int *len, char *str)
{
	ssize_t	write_len;

	if (str == NULL)
		return (-1);
	write_len = ft_write_aligned_left(fd, str, *len, field_width);
	if (write_len < 0 || INT_MAX < write_len)
		return (-1);
	return ((int)write_len);
}
