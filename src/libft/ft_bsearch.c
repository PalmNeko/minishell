/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:39:09 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/31 02:39:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "libft.h"

/**
 * @brief binary search
 * @param bsearch_args included in libft.h
 * @return Null if didn't find. first finded pointer if finded.
 */
void	*ft_bsearch(t_bsearch_arg *arg)
{
	size_t	left;
	size_t	right;
	size_t	middle;
	int		compare_result;

	left = 0;
	right = arg->nmemb;
	while (left < right)
	{
		middle = (left + right) / 2;
		compare_result = arg->compar(
				arg->base + (arg->size * middle), arg->key);
		if (compare_result < 0)
			left = middle + 1;
		else
			right = middle;
	}
	if (arg->compar(arg->base + (arg->size * left), arg->key) == 0)
		return ((void *)(arg->base + (arg->size * left)));
	return (NULL);
}
