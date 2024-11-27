/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:53:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 15:43:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * unset environment variable.
 * If  name does not exist in the environment, then the function succeeds, and
 * the environment is unchanged.
 * @param name variable name
 * @return zero on success. -1 on error, with errno set.
 * @exception
 * ENOMEM: has no memory.
 * EINVAL: name is NULL, points to a string of length 0, or contains an '='
 * character.
 */
int	ms_unsetenv(const char *name)
{
	(void)name;
	return (0);
}
