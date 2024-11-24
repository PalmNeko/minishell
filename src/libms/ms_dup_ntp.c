/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dup_ntp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:17:33 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 22:17:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include <stdlib.h>

/**
 * copy null terminated string array.
 * @param ntp coping target. null terminated string array.
 * @return copied null terminated string array on memory.
 * You must free this value with ms_destroy_ntp.
 */
char	**ms_dup_ntp(const char *ntp[])
{
	size_t	index;
	char	**duped_ntp;

	index = 0;
	while (ntp[index] != NULL)
		index++;
	duped_ntp = (char **)ft_calloc((index + 1), sizeof(char *));
	if (duped_ntp == NULL)
		return (NULL);
	index = 0;
	while (ntp[index] != NULL)
	{
		duped_ntp[index] = ft_strdup(ntp[index]);
		if (duped_ntp[index] == NULL)
			return (ms_destroy_ntp(duped_ntp), NULL);
		index++;
	}
	duped_ntp[index] = NULL;
	return (duped_ntp);
}
