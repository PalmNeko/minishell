/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getopt_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:03:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 16:12:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_getopt_type.h"
#include "ms_getopt_internal.h"
#include <stdlib.h>
#include <stdbool.h>

void	ms_behavior_on_not_option(t_opting *opting);
void	ms_behavior_on_option(t_opting *opting);

/**
 * @brief Parse the next option.
 * @param opting The initialized optioning structure.
 * @return true if the read character is option, false otherwise.
 * set the optopt to the read character if the read character is option.
 * set the is_valid to true if the read character is option and it is valid.
 */
bool	ms_getopt_parse(t_opting *opting)
{
	if (ms_is_parsed(opting))
		return (false);
	if (ms_go_is_option(opting->argv[opting->optind]) != true)
	{
		ms_behavior_on_not_option(opting);
		return (false);
	}
	ms_behavior_on_option(opting);
	return (true);
}

void	ms_behavior_on_not_option(t_opting *opting)
{
	ms_skip_double_hyphen_if_needed(opting);
	opting->internal.is_parsed = true;
}

void	ms_behavior_on_option(t_opting *opting)
{
	char	*arg;
	int		opt;

	arg = opting->argv[opting->optind];
	opt = arg[opting->internal.optpos];
	opting->nowind = opting->optind;
	opting->optopt = opt;
	opting->is_valid = ms_opt_is_valid(opt, opting->optstring);
	opting->is_valid_optstatement = ms_is_valid_statement(
			arg, opting->optstring);
	opting->internal.optpos++;
	if (opting->argv[opting->optind][opting->internal.optpos] == '\0')
	{
		opting->optind++;
		opting->internal.optpos = 1;
	}
}
