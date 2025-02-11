/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exports.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:38:45 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/02 07:41:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*g_exports;

t_list	*ms_get_exports(void)
{
	return (g_exports);
}

void	ms_set_exports(t_list *exports)
{
	g_exports = exports;
}

void	ms_clear_exports(void)
{
	ft_lstclear(&g_exports, free);
}
