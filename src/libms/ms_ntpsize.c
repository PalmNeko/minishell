/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/libft/fp_modules/fp_get_sign_type.c
/*   fp_get_sign_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:36:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 15:38:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module_types.h"
#include "fp_module_int_defs.h"

int	fp_get_sign_type(t_cs *cs)
{
	if (cs->flag_plus)
		return (FP_SSIGN);
	else if (cs->flag_space)
		return (FP_SSPACE);
	else
		return (FP_SDEFAULT);
========
/*   ms_ntpsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:19:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/28 19:07:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

size_t	ms_ntpsize(void **ntp)
{
	size_t	size;

	size = 0;
	if (ntp == NULL)
		return (0);
	while (*ntp != NULL && size < SIZE_MAX)
	{
		size++;
		ntp++;
	}
	return (size);
>>>>>>>> origin/main:src/libms/ms_ntpsize.c
}
