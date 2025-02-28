/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:46:46 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 16:47:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ECHO_H
# define BUILTIN_ECHO_H

# include "builtin_echo_type.h"

int	ms_parse_builtin_echo_arg(
		t_builtin_echo *parsed,
		const char *path,
		char *const argv[],
		char *const envp[]);

#endif
