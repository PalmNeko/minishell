/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_cdwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:09:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 15:09:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "builtin_internal.h"
#include "libft.h"

char	*ms_get_cdwd(void)
{
	char	**cdwd;

	cdwd = ms_get_raw_cdwd();
	if (*cdwd == NULL)
		*cdwd = ms_get_current_dir_name();
	if (*cdwd == NULL)
		return (NULL);
	return (ft_strdup(*cdwd));
}
