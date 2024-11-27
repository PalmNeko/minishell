/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
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
}
