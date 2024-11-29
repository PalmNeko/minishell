/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_destroy_ntp2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:16:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 17:38:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

/**
 * release any ntp
 * @param ntp null terminated array
 * @param fr release function
 */
void	ms_destroy_ntp2(void **ntp, void (*fr)(void *))
{
	size_t	index;

	if (ntp == NULL)
		return ;
	index = 0;
	while (ntp[index] != NULL)
	{
		fr(ntp[index]);
		index++;
	}
	free(ntp);
}
