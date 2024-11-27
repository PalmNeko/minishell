/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrightalign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:03:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/04 13:52:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief generate left align text.
 * @param s1 plane text.
 * @param min_width text's full min width.
 * @return aligned left text. NULL if an error occurs.
 * @details
 * 	if min_width > (s1's len), returned length is min_width.
 * 	if min_width < (s1's len), returned length is (s1's length).
*/
char	*ft_strrightalign(const char *s1, size_t min_width)
{
	size_t	len;
	size_t	space_len;
	char	*space;
	char	*aligned;

	len = ft_strlen(s1);
	if (min_width > len)
		space_len = min_width - len;
	else
		space_len = 0;
	space = ft_strrepeat(" ", space_len);
	if (space == NULL)
		return (NULL);
	aligned = ft_strjoin(space, s1);
	free(space);
	return (aligned);
}
