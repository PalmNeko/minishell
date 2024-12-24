/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_arg_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:39:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/04 15:39:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

int ms_check_arg_num(char *const argv[], int min, int max)
{
	size_t	len;

	len = ms_ntpsize((void **)argv);
	if (len < (size_t)min || len > (size_t)max)
		return (1);
	return (0);
}
