/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit_itr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:10:43 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 17:10:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_lstitrhas_next(t_iter *itr);
static void	*ft_lstitrnext(t_iter *itr);

void	ft_lstinit_itr(t_list *lst, t_iter *itr)
{
	itr->current = lst;
	itr->start = lst;
	itr->end = ft_lstlast(lst);
	itr->index = 0;
	itr->has_next = ft_lstitrhas_next;
	itr->next = ft_lstitrnext;
	return ;
}

static bool	ft_lstitrhas_next(t_iter *itr)
{
	if (itr->current == NULL)
		return (false);
	else
		return (true);
}

static void	*ft_lstitrnext(t_iter *itr)
{
	t_list	*result;

	result = itr->current;
	if (result != NULL)
	{
		if (itr->current == itr->end)
			itr->current = NULL;
		else
			itr->current = result->next;
		itr->index++;
	}
	return (result);
}
