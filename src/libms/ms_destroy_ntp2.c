<<<<<<<< HEAD:src/libft/ft_lstat.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:25:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/27 17:25:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list, int no)
{
	int		index;
	t_list	*first;

	first = ft_lstfirst(list);
	list = first;
	index = 0;
	while (index < no)
	{
		if (list == NULL)
			return (NULL);
		list = list->next;
		index++;
	}
	if (list != NULL)
		return (list);
	return (NULL);
}
========
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_destroy_ntp2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:16:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/28 19:06:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

/**
 * release any ntp
 * @param ntp null terminated array
 * @param fr release function
 */
void	ms_destroy_ntp2(void **ntp, void (*fr)(void *))
{
	size_t	index;

	if (ntp == NULL)
		return ;
	index = 0;
	while (ntp[index] != NULL)
	{
		fr(ntp[index]);
		index++;
	}
	free(ntp);
}
>>>>>>>> origin/main:src/libms/ms_destroy_ntp2.c
