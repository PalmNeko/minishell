/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strrep_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:12:58 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/18 18:19:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ms_trim_end_newline(char *str)
{
	char	*chr;

	chr = ft_strrchr(str, '\n');
	if (chr == NULL)
		return (1);
	*chr = '\0';
	return (0);
}
