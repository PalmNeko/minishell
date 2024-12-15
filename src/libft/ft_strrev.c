/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:52:06 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 17:01:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_strrev(char *str)
{
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(str);
	if (right > 0)
		right -= 1;
	while (left < right)
	{
		ft_swap_chr(&str[left], &str[right]);
		left += 1;
		right -= 1;
	}
	return ;
}
