/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_update_environs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 06:53:31 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/28 06:57:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

void	ms_update_environs(void)
{
	if (ms_getenv("MNSH_SUBSHELL") == NULL)
		ms_set_mnsh_subshell_var_enabled(false);
}
