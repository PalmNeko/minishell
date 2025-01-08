/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:00:05 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:04:31 by tookuyam         ###   ########.fr       */
=======
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:00:05 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/28 19:05:39 by tookuyam         ###   ########.fr       */
>>>>>>> origin/main
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
