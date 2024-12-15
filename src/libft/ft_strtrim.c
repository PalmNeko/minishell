/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:21:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 17:54:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static int	is_includes(char c, char const *set);
static char	*strskip(char const *s1, char const *set);
static char	*strrskip(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of
 * 's1' with the characters specified in 'set' removed
 * from the beginning and the end of the string.
 * @param s1 - The string to be trimmed.
 * @param set - The reference set of characters to trim.
 * @return The trimmed string.
 * NULL if the allocation fails.
 * @example
 * ```
 * #include "libft.h"
 * #include <stdlib.h>
 *
 * ...
 *
 * char	*trimmed;
 * trimmed = ft_strtrim("''abc','def''", "',"); // will be return `abc'.'def`
 * if (trimmed == NULL)
 * 	return ;
 *
 * ...
 *
 * free(trimmed);
 * ```
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	char	*start;
	char	*end;
	size_t	size;

	start = strskip(s1, set);
	end = strrskip(start, set);
	size = (end - start) + 1;
	trim = (char *)malloc(sizeof(char) * size);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, start, size);
	return (trim);
}

static char	*strskip(char const *s1, char const *set)
{
	while (is_includes(*s1, set))
		s1++;
	return ((char *)s1);
}

static char	*strrskip(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len >= 1 && is_includes(s1[len - 1], set))
		len--;
	return ((char *)(s1 + len));
}

static int	is_includes(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (!0);
		set++;
	}
	return (0);
}
