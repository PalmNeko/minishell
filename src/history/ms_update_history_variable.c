/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_update_history_variable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:20:46 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 12:10:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "history.h"
#include "internal/history_internal.h"

void	ms_update_history_variable(void)
{
	char		*histsize_str;
	int			histsize;

	histsize = -1;
	histsize_str = ms_getenv("HISTSIZE");
	if (histsize_str != NULL)
		histsize = ft_atoi(histsize_str);
	ms_stifle_history(histsize);
}
