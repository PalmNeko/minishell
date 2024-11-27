/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:53:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/23 17:53:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0' && s1[count] == s2[count])
		count++;
	if (s1[count] != s2[count])
		return (((unsigned char)s1[count] - (unsigned char)s2[count]));
	return (0);
}
