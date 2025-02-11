/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:36:09 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/01 09:53:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_INTERNAL_H
# define EXIT_INTERNAL_H

# include "exit_internal_type.h"

int	ms_parse_builtin_exit(t_builtin_exit *parsed, char *const argv[]);

#endif
