/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_builtin_echo_arg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:46:25 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 16:48:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_echo_type.h"
#include "libms.h"
#include "ms_getopt.h"

int	ms_parse_builtin_echo_arg(
		t_builtin_echo *parsed,
		const char *path,
		char *const argv[],
		char *const envp[])
{
	int			argc;
	t_opting	opting;

	(void)path;
	(void)envp;
	parsed->is_n = false;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "n");
	opting.is_skip_double_hyphen = false;
	while (ms_getopt_parse(&opting))
	{
		if (opting.is_valid_optstatement == false)
			break ;
		parsed->is_n = true;
	}
	parsed->arg_index = opting.optind;
	return (0);
}
