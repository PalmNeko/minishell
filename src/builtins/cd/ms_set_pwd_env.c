/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_pwd_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:21:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 16:21:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include <stdlib.h>

int	ms_set_pwd_env(const char *new_path)
{
	char	*old_cdwd;
	int		result;

	old_cdwd = ms_get_cdwd();
	if (old_cdwd == NULL)
		return (1);
	result = ms_setenv("OLDPWD", old_cdwd, 1);
	if (result != 0)
		return (1);
	ms_set_cdwd(new_path);
	if (ms_setenv("PWD", new_path, 1) != 0)
		return (1);
	return (0);
}
