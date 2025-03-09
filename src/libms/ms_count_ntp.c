/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_count_ntp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:18:13 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/09 17:01:12 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ms_count_ntp(void **ntp)
{
	size_t	index;

	if (ntp == NULL)
		return (0);
	index = 0;
	while (ntp[index] != NULL)
		index++;
	return (index);
}
