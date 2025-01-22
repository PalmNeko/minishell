/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms_internal_type.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:44:16 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 08:28:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_INTERNAL_TYPE_H
# define LIBMS_INTERNAL_TYPE_H

# include "libms_type.h"

typedef struct ms_var {
	char			*name;
	char			*value;
	t_ms_var_type	attr;
}	t_ms_var;

#endif
