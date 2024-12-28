/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:36:33 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 15:36:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"

/**
 * split string by separator.
 * @param str string to be splitted
 * @param sep separator
 * @return splitted strings
 * @example
 * ms_split("abc:def", ':') => ["abc", "def", NULL]
 * ms_split(":", ':') => ["", "", NULL]
 */
char	**ms_separate(const char *str, char sep)
{
	char	**separated;
	char	*itr;
	size_t	cnt;

	cnt = 0;
	itr = (char *)str;
	while (*itr != '\0')
		if (*(itr++) == sep)
			cnt++;
	separated = ft_calloc(cnt + 2, sizeof(char *));
	if (separated == NULL)
		return (NULL);
	itr = (char *)str;
	cnt = 0;
	while (itr != NULL && *itr != '\0')
	{
		separated[cnt] = ms_strdup_sep(itr, sep);
		if (separated[cnt] == NULL)
			return (ms_destroy_ntp(separated), NULL);
		itr = ft_strchr(itr, sep);
		if (itr == NULL)
			break ;
	}
	return (separated);
}
