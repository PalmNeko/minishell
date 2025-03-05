/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:28:18 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/04 17:23:59 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_TYPE_H
# define LIBMS_TYPE_H

typedef enum e_ms_var_type
{
	ATTR_NONE = 0,
	ATTR_SHELL_VAR = 1,
	ATTR_ENV = 2,
	ATTR_EXPORT = 4,
}	t_ms_var_type;

typedef enum e_ms_status_meta_type
{
	IS_CHILD = (1 << 8)
}	t_ms_status_meta_type;

#endif
