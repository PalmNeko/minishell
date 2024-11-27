/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:29:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/06 12:11:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "libft.h"

bool	match_one(char *pattern, char *text);
bool	match_plus(char *pattern, char *text);
bool	_match(char *pattern, char *text);

/**
 * @brief match with regex pattern
 * @param pattern ExpRegex. you can use '^$.*+'. not supported '[]', '()'...
 * '^$.*+' can escape '\\'.
 * example: ft_match("sample\\.txt$", "sample.txt") => true.
 * @param text search text
 * @return true if match pattern. false if not match pattern.
 */
bool	ft_strmatch(char *pattern, char *text)
{
	if (pattern[0] == '^')
		return (_match(pattern + 1, text));
	else
	{
		while (*text != '\0')
		{
			if (_match(pattern, text))
				return (true);
			text++;
		}
	}
	return (false);
}

bool	_match(char *pattern, char *text)
{
	if (pattern[0] == '\0')
		return (true);
	else if (pattern[0] == '$')
		return (pattern[1] == '\0' && text[0] == '\0');
	else if (pattern[0] == '\\')
	{
		if (ft_includes(pattern[1], "$."))
			return (text[0] == pattern[1] && _match(pattern + 2, text + 1));
		else
			return (_match(pattern + 1, text));
	}
	else if (pattern[1] == '?')
		return ((match_one(pattern, text) && _match(pattern + 2, text + 1))
			|| _match(pattern + 2, text));
	else if (pattern[1] == '*')
		return (_match(pattern + 2, text)
			|| (match_one(pattern, text) && _match(pattern, text + 1)));
	else if (pattern[1] == '+')
		return (match_plus(pattern, text));
	else if (match_one(pattern, text))
		return (_match(pattern + 1, text + 1));
	return (false);
}

bool	match_plus(char *pattern, char *text)
{
	if (pattern[1] != '+')
		return (false);
	if (match_one(pattern, text) == false)
		return (false);
	text += 1;
	while (match_one(pattern, text))
		text += 1;
	return (_match(pattern + 2, text));
}

bool	match_one(char *pattern, char *text)
{
	if (pattern[0] == '\0')
		return (true);
	else if (text[0] == '\0')
		return (false);
	else if (ft_includes(pattern[0], "^*+$"))
		return (false);
	else if (pattern[0] == text[0])
		return (true);
	else if (pattern[0] == '.')
		return (true);
	return (false);
}
