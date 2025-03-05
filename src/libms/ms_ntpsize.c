/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_ntpsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:19:32 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/05 13:47:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

size_t	ms_ntpsize(void **ntp)
{
	size_t	size;

	size = 0;
	if (ntp == NULL)
		return (0);
	while (*ntp != NULL && size < SIZE_MAX)
	{
		size++;
		ntp++;
	}
	return (size);
}
