/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:26 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/27 17:42:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_INTERNAL_H
# define EXPORT_INTERNAL_H

# include "export_internal_type.h"

int		ms_export_print_command(void);
int		ms_export_variables(const char **args);
char	**ms_export_environs(void);
bool	ms_export_variable_validate_arg(const char *arg);

#endif
