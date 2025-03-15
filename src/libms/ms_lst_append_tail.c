/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lst_append_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:43:20 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 21:57:16 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ms_lst_append_tail(t_list **lst, void *contents)
{
	t_list	*new;

	new = ft_lstnew(contents);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}
