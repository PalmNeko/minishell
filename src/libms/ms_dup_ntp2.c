/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dup_ntp2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:08:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 22:08:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

/**
 * same as ms_dup_ntp except type is different.
 */
char	**ms_dup_ntp2(const char *const ntp[])
{
	return (ms_dup_ntp((const char **)ntp));
}
