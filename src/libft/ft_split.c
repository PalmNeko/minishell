/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:10:33 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:41:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

static char	**allocate_splitted_memory(char const *s, char c);
static char	**free_splitted(char **splitted);

char	**ft_split(char const *s, char c)
{
	size_t		index;
	char const	*start_ptr;
	char		**splitted;

	splitted = allocate_splitted_memory(s, c);
	if (splitted == NULL)
		return (NULL);
	index = 0;
	while (*s != '\0')
	{
		start_ptr = s;
		while (*s != c && *s != '\0')
			s++;
		if (s - start_ptr != 0)
		{
			splitted[index++] = ft_strndup(start_ptr, s - start_ptr);
			if (splitted[index - 1] == NULL)
				return (free_splitted(splitted));
		}
		while (*s == c && *s != '\0')
			s++;
	}
	splitted[index] = NULL;
	return (splitted);
}

static char	**allocate_splitted_memory(char const *s, char c)
{
	size_t		count;
	char const	*start_ptr;
	char		**splitted;

	count = 0;
	while (*s != '\0')
	{
		start_ptr = s;
		while (*s != c && *s != '\0')
			s++;
		if (s - start_ptr != 0)
			count++;
		while (*s == c && *s != '\0')
			s++;
	}
	splitted = (char **)malloc(sizeof(char *) * (count + 1));
	return (splitted);
}

static char	**free_splitted(char **splitted)
{
	size_t	index;

	index = 0;
	while (splitted[index] != NULL)
	{
		free(splitted[index]);
		index++;
	}
	free(splitted);
	return (NULL);
}
