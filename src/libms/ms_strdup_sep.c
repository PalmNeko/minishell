/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strdup_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:30:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 15:30:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * create substring until sep.
 * @param str string to be copied
 * @param sep separator
 * @return copied string if success. NULL if failed.
 * @exception
 * ENOMEM: failed to allocate memory
 * @example
 * ms_strdup_sep("abc:def", ':') => "abc"
 * ms_strdup_sep(":", ':') => ""
 */
char	*ms_strdup_sep(const char *str, char sep)
{
	char	*sep_ptr;

	sep_ptr = ft_strchr(str, sep);
	if (sep_ptr == NULL)
		sep_ptr = ft_strchr(str, '\0');
	return (ft_strndup(str, sep_ptr - str));
}
