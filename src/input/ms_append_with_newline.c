/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_append_with_newline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:24:48 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/13 14:24:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ms_append_with_newline(char **input, const char *input_line)
{
	char	*joined_text;
	char	*appended_newline_text;

	joined_text = ft_strjoin(*input, input_line);
	if (joined_text == NULL)
		return (NULL);
	appended_newline_text = ft_strjoin(joined_text, "\n");
	free(joined_text);
	if (appended_newline_text == NULL)
		return (NULL);
	free(*input);
	*input = appended_newline_text;
	return (*input);
}
