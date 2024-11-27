/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:40:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:43:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_iter(t_free_args *free_args, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		free_args[index].free_func(free_args[index].arg);
		index++;
	}
	return ;
}
