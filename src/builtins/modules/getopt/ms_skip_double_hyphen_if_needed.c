/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_skip_double_hyphen_if_needed.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:16:16 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 15:51:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ms_getopt_type.h"
#include <stddef.h>

void	ms_skip_double_hyphen_if_needed(t_opting *opting)
{
	if (opting->argv[opting->optind] != NULL
		&& ft_strcmp(opting->argv[opting->optind], "--") != 0)
		return ;
	if (opting->is_skip_double_hyphen)
		opting->optind++;
	return ;
}
