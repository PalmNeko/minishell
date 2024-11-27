/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkostemp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:20:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/02 18:35:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include "libft.h"

int	ft_mkostemp(char *template, int flags)
{
	size_t		len;
	int			index;
	int			fd;

	len = ft_strlen(template);
	if (len < 6 || ! ft_strmatch("XXXXXX$", template))
	{
		errno = EINVAL;
		return (-1);
	}
	flags |= O_RDWR | O_CREAT | O_EXCL;
	index = 0;
	while (index < 10)
	{
		errno = 0;
		ft_replace_random_alpha(
			&template[len - 6], 6, ft_addr2uint32_t(template), 6 * index);
		fd = open(template, flags, S_IWUSR | S_IRUSR);
		if (fd != -1 || (fd == -1 && errno != EEXIST))
			return (fd);
		index++;
	}
	errno = EEXIST;
	return (-1);
}
