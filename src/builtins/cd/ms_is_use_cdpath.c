/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_use_cdpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:23:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 16:23:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"

bool	ms_is_use_cdpath(const char *path)
{
	char	*text;

	text = (char *)path;
	if (text == NULL)
		return (false);
	if (ft_strmatch("/.*", text))
		return (false);
	if (ft_strmatch("\\./.*", text))
		return (false);
	if (ft_strmatch("\\.\\./.*", text))
		return (false);
	if (ms_getenv("CDPATH") == NULL)
		return (false);
	return (true);
}
