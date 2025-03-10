/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_ntpsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:19:32 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/10 20:04:25 by rnakatan         ###   ########.fr       */
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
