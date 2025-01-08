/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:00:05 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/08 12:18:40 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sp;
	size_t			set_count;

	sp = s;
	set_count = 0;
	while (set_count < n)
		sp[set_count++] = 0;
	return ;
}
