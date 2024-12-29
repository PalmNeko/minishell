/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_get_environ_variable.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:03 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 15:46:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*g_int_environ = NULL;

/**
 * return g_int_environ pointer;
 */
t_list	**ms_int_get_environ_variable(void)
{
	return (&g_int_environ);
}
