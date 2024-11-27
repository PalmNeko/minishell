/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dup_ntp3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 15:39:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libms.h"

/**
 * same as ms_dup_ntp except type is different.
 */
char	**ms_dup_ntp3(char *ntp[])
{
	return (ms_dup_ntp((const char **)ntp));
}
