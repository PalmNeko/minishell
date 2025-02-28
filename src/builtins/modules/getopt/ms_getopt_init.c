/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getopt_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:24:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 16:16:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_getopt_type.h"

int	ms_getopt_init(
		t_opting *opting, int argc, char *argv[], const char *optstring)
{
	opting->argc = argc;
	opting->argv = argv;
	opting->optstring = (char *)optstring;
	opting->is_skip_double_hyphen = true;
	opting->is_valid = false;
	opting->is_valid_optstatement = false;
	opting->optind = 1;
	opting->nowind = 1;
	opting->optopt = 0;
	opting->internal.is_parsed = false;
	opting->internal.optpos = 1;
	return (0);
}
