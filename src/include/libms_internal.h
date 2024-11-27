/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:49:40 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 16:30:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_INTERNAL_H
# define LIBMS_INTERNAL_H

# include "libft_type.h"
# include "libms_internal_type.h"

t_list		**ms_int_get_environ_variable(void);
t_ms_var	*ms_int_create_ms_var(const char *name, const char *value);
t_ms_var	*ms_int_generate_ms_var_from_text(const char *text);
void		ms_int_destroy_ms_var(t_ms_var *ms_var);

#endif
