/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:24:07 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/18 18:00:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include <stdlib.h>

char	*ms_tilde_expansion(const char *path)
{
	char	*home;
	char	*expanded;

	if (ft_strncmp(path, "~/", 2) != 0)
		return (ft_strdup(path));
	home = ms_getenv("HOME");
	if (home == NULL)
		return (ft_strdup(path));
	expanded = ft_strjoin(home, path + 1);
	return (expanded);
}
