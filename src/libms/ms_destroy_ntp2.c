/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_destroy_ntp2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:16:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/08 12:20:51 by rnakatan         ###   ########.fr       */
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
