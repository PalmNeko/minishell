/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:31:18 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:23:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

size_t	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	return (write(fd, s, len));
}
