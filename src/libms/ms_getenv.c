/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:55:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 15:43:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * get value of name from now environment.
 * @param name name of environment variable
 * @return  pointer to environment value address if succeeded.
 * null-pointer if occurs an error.
 * @note
 * you mustn't release return value.
 */
char	*ms_getenv(const char *name)
{
	(void)name;
	return (NULL);
}
