/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:57:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/11 16:52:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 * @brief get value in memory from environ.environ(7)
 * @param name keyvalue
 */
char	*ft_getenv(const char *name)
{
	extern char	**environ;
	char		*find_iter;
	size_t		index;

	index = 0;
	while (environ[index] != NULL)
	{
		find_iter = ft_strchr(environ[index], '=');
		if (find_iter != NULL && ft_strncmp(
				name, environ[index], find_iter - environ[index]) == 0)
			break ;
		index++;
	}
	if (environ[index] == NULL)
		return (NULL);
	if (find_iter != NULL)
		find_iter += 1;
	return (find_iter);
}
