/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_pad_for_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:22:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 14:53:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*fp_pad_for_num(int zero_field_width, int *size, char *str)
{
	char	*joined;
	char	*tmp;
	char	*zero_nums;
	int		sign_offset;

	if (str == NULL)
		return (NULL);
	if (*size > zero_field_width)
		return (ft_strdup(str));
	zero_nums = ft_strrepeat("0", zero_field_width - *size);
	if (zero_nums == NULL)
		return (NULL);
	*size = zero_field_width;
	sign_offset = 0;
	if (str[0] == '-')
		sign_offset = 1;
	tmp = ft_strjoin(zero_nums, str + sign_offset);
	free(zero_nums);
	if (tmp == NULL)
		return (NULL);
	joined = ft_strjoin(&"-"[(1 - sign_offset)], tmp);
	free(tmp);
	return (joined);
}
