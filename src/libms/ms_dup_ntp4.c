/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dup_ntp4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:40:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

/**
 * same as ms_dup_ntp except type is different.
 */
char	**ms_dup_ntp4(char *const ntp[])
{
	return (ms_dup_ntp((const char **)ntp));
}
