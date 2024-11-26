/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:00:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/14 21:00:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	ft_selection_sort(void *base, size_t num, size_t size,
	int (*f_cmp)(const void *n1, const void *n2))
{
	void	*min_ptr;
	char	*data;
	size_t	target;
	size_t	iterator;

	target = 0;
	data = base;
	while (target < num)
	{
		iterator = target + 1;
		min_ptr = data + (target * size);
		while (iterator < num)
		{
			if (f_cmp(min_ptr, data + (iterator * size)) > 0)
				min_ptr = data + (iterator * size);
			iterator++;
		}
		ft_memswap(min_ptr, data + (target * size), size);
		target++;
	}
}
