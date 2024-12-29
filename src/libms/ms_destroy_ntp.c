/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_destroy_ntp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:11:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 22:11:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * release null terminated string array on mmemory.
 * @param ntp null terminated string array
 */
void	ms_destroy_ntp(char *ntp[])
{
	size_t	index;

	if (ntp == NULL)
		return ;
	index = 0;
	while (ntp[index] != NULL)
	{
		free(ntp[index]);
		index++;
	}
	free(ntp);
}
