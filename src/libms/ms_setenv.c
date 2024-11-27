/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:54:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 15:44:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * set environment variable according to `overwrite`.
 * @param name variable name
 * @param value variable value.
 * @param overwrite if overwrite is nonzero; if overwrite is zero, then the
 * value of name  is  not  changed
 * @return zero on success. -1 on error, with errno set.
 * @exception
 * ENOMEM: has no memory.
 * EINVAL: name is NULL, points to a string of length 0, or contains an '='
 * character.
 */
int	ms_setenv(const char *name, const char *value, int overwrite)
{
	(void)name;
	(void)value;
	(void)overwrite;
	return (0);
}
