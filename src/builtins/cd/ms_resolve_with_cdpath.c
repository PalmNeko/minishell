/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_resolve_with_cdpath.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 16:25:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cd_internal.h"
#include "builtin_internal.h"
#include <stddef.h>
#include <stdlib.h>

char	*ms_resolve_with_cdpath(const char *path)
{
	char	*resolved_path;

	resolved_path = ms_search_with_cdpath(path);
	if (resolved_path == NULL)
		resolved_path = ft_strdup(path);
	return (resolved_path);
}
