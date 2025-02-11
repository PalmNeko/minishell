/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_parsed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:15:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 15:59:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_getopt_type.h"
#include <stdbool.h>

bool	ms_is_parsed(t_opting *opting)
{
	if (opting->internal.is_parsed)
		return (true);
	else if (opting->optind >= opting->argc)
		return (true);
	return (false);
}
