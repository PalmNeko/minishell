/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_skip_until_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:29:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/05 13:45:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input.h"

void	ms_skip_until_heredoc(char **input)
{
	while (**input != '\0')
	{
		if (ft_includes (**input, "'\""))
		{
			ms_skip_surround_quote(input);
			continue ;
		}
		if (ft_strncmp(*input, "<<", 2) == 0)
			return ;
		(*input)++;
	}
}
