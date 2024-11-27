/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_generate_ms_var_from_text.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:53:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 16:13:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms_internal_type.h"
#include <stddef.h>

/**
 * generate t_ms_var variable from formatted text.
 * @param text text for set value format: name=[value]
 * @return pointer to ms_var on success. Null on error and set errno.
 * @exception
 * ENOMEM: has no memory
 * EINVAL: text format is incorrect.
 */
t_ms_var	*ms_int_generate_ms_var_from_text(const char *text)
{
	(void)text;
	return (NULL);
}
