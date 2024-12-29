/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_destroy_ms_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:00:01 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:01:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms_internal_type.h"
#include <stdlib.h>

void	ms_int_destroy_ms_var(t_ms_var *ms_var)
{
	if (ms_var == NULL)
		return ;
	free(ms_var->name);
	free(ms_var->value);
	free(ms_var);
	return ;
}
