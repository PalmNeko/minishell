/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_skip_surround_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:45:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/05 13:45:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ms_skip_surround_quote(char **input)
{
	char	quote_txt[2];
	char	*ptr;

	ptr = *input;
	if (!ft_includes(*ptr, "'\""))
		return ;
	quote_txt[1] = '\0';
	quote_txt[0] = *ptr;
	ptr++;
	while (*ptr != '\0' && ! ft_includes(*ptr, quote_txt))
		ptr++;
	if (*ptr != '\0')
		ptr++;
	*input = ptr;
}
