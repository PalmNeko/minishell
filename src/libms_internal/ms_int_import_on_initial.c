/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_import_on_initial.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:05:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:15:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libms_internal.h"

int	ms_int_import_on_initial(void)
{
	t_list		**env_list;
	extern char	**environ;

	env_list = ms_int_get_environ_variable();
	if (*env_list != NULL)
		return (0);
	return (ms_import_env(environ));
}
