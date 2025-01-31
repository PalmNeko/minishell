/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_compare_heredoc_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:26:06 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/29 12:26:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ms_compare_heredoc_input(const char *input, const char *delimiter)
{
	size_t	input_len;
	size_t	delimiter_len;

	input_len = ft_strlen(input);
	delimiter_len = ft_strlen(delimiter);
	if (input_len > 0 && input[input_len - 1] == '\n')
		input_len--;
	if (delimiter_len > 0 && delimiter[delimiter_len - 1] == '\n')
		delimiter_len--;
	if (input_len != delimiter_len)
		return (false);
	if (ft_strncmp(input, delimiter, input_len) != 0)
		return (false);
	return (true);
}
