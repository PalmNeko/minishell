/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lst_to_ntp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:07:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 17:22:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include <stdlib.h>

/**
 * lst to null terminated content.
 * lst will no longer be available because release memory in this function.
 * if including content which is null, this value is not included.
 * @param lst content list
 * @param cp copy function
 * @param fr free function
 * @return null terminated pointer
 * @exception
 * ENOMEM: has no memory.
 * @example
 * ntp = (char **)ms_lst_to_ntp(&lst);
 */
void	*ms_lst_to_ntp(t_list **lst, void *(*cp)(void *), void (*fr)(void *))
{
	int		size;
	int		index;
	void	**ntp;
	t_list	*itr;

	size = ft_lstsize(*lst);
	ntp = (void **)malloc(sizeof(void *) * (size + 1));
	if (ntp == NULL)
		return (NULL);
	itr = *lst;
	index = 0;
	while (itr != NULL && itr->content != NULL)
	{
		ntp[index] = cp(itr->content);
		if (ntp[index] == NULL)
			return (ms_destroy_ntp2(ntp, fr), NULL);
		itr = itr->next;
		index++;
	}
	ntp[index] = NULL;
	ft_lstclear(lst, fr);
	*lst = NULL;
	return (ntp);
}
