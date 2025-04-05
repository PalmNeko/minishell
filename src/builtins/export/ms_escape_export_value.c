/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_escape_export_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:59:29 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/05 05:08:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ms_escapestr_len(const char *str);
static char		*ms_escapestr_cpy(char escapestr_buf[3], int c);

char	*ms_escape_export_value(const char *value)
{
	size_t	len;
	size_t	cat_len;
	char	*escaped_value;
	char	*ptr;
	char	escaped_str[3];

	len = ms_escapestr_len(value);
	escaped_value = malloc(len + 1);
	if (escaped_value == NULL)
		return (NULL);
	escaped_value[0] = '\0';
	ptr = escaped_value;
	while (*value != '\0')
	{
		ms_escapestr_cpy(escaped_str, *value);
		cat_len = ft_strlcat(ptr, escaped_str, len + 1);
		len -= cat_len;
		ptr += cat_len;
		value++;
	}
	return (escaped_value);
}

static size_t	ms_escapestr_len(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\\' || *str == '"')
			len += 2;
		else
			len += 1;
		str++;
	}
	return (len);
}

static char	*ms_escapestr_cpy(char escapestr_buf[3], int c)
{
	if (c == '\\')
	{
		escapestr_buf[0] = '\\';
		escapestr_buf[1] = '\\';
		escapestr_buf[2] = '\0';
	}
	else if (c == '"')
	{
		escapestr_buf[0] = '\\';
		escapestr_buf[1] = '"';
		escapestr_buf[2] = '\0';
	}
	else
	{
		escapestr_buf[0] = c;
		escapestr_buf[1] = '\0';
	}
	return (escapestr_buf);
}
