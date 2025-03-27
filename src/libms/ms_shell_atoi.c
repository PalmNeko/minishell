/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_shell_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:32:27 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 07:36:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ms_shell_atoi(const char *str)
{
	char	*endptr;
	int		ret;

	ret = ft_strtol(str, &endptr, 10);
	if (*endptr != '\0')
		return (0);
	return (ret);
}
