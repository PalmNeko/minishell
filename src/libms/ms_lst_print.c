/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:45:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/29 11:45:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ms_lst_print(t_list *lst, void (*print)(void *))
{
	while (lst != NULL)
	{
		print(lst->content);
		lst = lst->next;
	}
}
