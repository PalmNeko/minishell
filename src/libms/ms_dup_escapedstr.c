/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dup_escapedstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:42:33 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/02 17:46:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ms_toescapedstr(char dest[11], const int chr);
static size_t	ms_escapedstrlen(const char *str);

/**
 * convert string includes special characters to escaped string.
 * use this escape list:
 * 		\a \b \e \f \n \r \t \v \ '
 * if the string includes non-printable characters and not included above
 * escape list, it is converted to octal: e.g. \337
 */
char	*ms_dup_escapedstr(const char *str)
{
	char	*escaped;
	char	*escaped_ptr;
	char	escaped_buf[11];
	size_t	escaped_len;
	size_t	catsize;

	escaped_len = ms_escapedstrlen(str);
	escaped = malloc((escaped_len + 1) * sizeof(char));
	if (escaped == NULL)
		return (NULL);
	escaped_ptr = escaped;
	escaped[0] = '\0';
	while (*str != '\0')
	{
		ms_toescapedstr(escaped_buf, *str);
		catsize = ft_strlcat(escaped, escaped_buf, escaped_len + 1);
		escaped_len -= catsize;
		escaped += catsize;
		str += 1;
	}
	return (escaped_ptr);
}

static char	*ms_toescapedstr(char dest[11], const int chr)
{
	const char	*escaped_str = "\a\b\e\f\n\r\t\v\\'";
	const char	*escaped_map = "\\a\\b\\e\\f\\n\\r\\t\\v\\\\\\'";
	char		*escaped_ptr;

	escaped_ptr = ft_strchr(escaped_str, chr);
	if (escaped_ptr != NULL)
		ft_strlcpy(dest, escaped_map + (escaped_ptr - escaped_str) * 2, 3);
	else if (ft_isprint(chr))
	{
		ft_strlcpy(dest, "x", 11);
		dest[0] = chr;
	}
	else
	{
		ft_strlcpy(dest, "\\000", 11);
		dest[3] = '0' + (unsigned char)chr % 8;
		dest[2] = '0' + ((unsigned char)chr >> 3) % 8;
		dest[1] = '0' + ((unsigned char)chr >> 6) % 8;
	}
	return (dest);
}

static size_t	ms_escapedstrlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		if (ft_includes(*str, "\a\b\e\f\n\r\t\v\\\'"))
			len += 2;
		else if (ft_isprint(*str))
			len++;
		else
			len += 4;
		str++;
	}
	return (len);
}
