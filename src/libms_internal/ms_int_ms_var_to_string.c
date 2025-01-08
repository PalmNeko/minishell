/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_ms_var_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 13:22:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms_internal.h"
#include "libft.h"

char	*ms_int_ms_var_to_string(t_ms_var *ms_var)
{
	char	*env_var_string;
	size_t	str_size;
	size_t	offset;

	str_size = ft_strlen(ms_var->name)
		+ ft_strlen("=")
		+ ft_strlen(ms_var->value)
		+ 1;
	env_var_string = ft_calloc(str_size, sizeof(char));
	if (env_var_string == NULL)
		return (NULL);
	offset = 0;
	offset += ft_strlcat(
			env_var_string + offset, ms_var->name, str_size - offset);
	offset += ft_strlcat(
			env_var_string + offset, "=", str_size - offset);
	offset += ft_strlcat(
			env_var_string + offset, ms_var->value, str_size - offset);
	return (env_var_string);
}
