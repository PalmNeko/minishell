/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_builtin_cd_args.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 05:45:21 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/21 11:12:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_getopt.h"
#include "builtin_internal.h"
#include "cd_internal_type.h"
#include "cd_internal.h"
#include "libms.h"
#include <stddef.h>
#include <string.h>
#include <errno.h>

static int	__ms_parse_builtin_cd_args(t_builtin_cd *parsed, t_opting *opting);

int	ms_parse_builtin_cd_args(
		t_builtin_cd *parsed,
		const char *path,
		char *const argv[],
		char *const envp[])
{
	int			argc;
	int			status;
	t_opting	opting;

	(void)path;
	(void)envp;
	parsed->chdir_pathname = NULL;
	parsed->is_set_cwd_error = false;
	parsed->symlink_follow = false;
	parsed->is_to_oldpwd = false;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "LPe");
	status = __ms_parse_builtin_cd_args(parsed, &opting);
	return (status);
}

static int	__ms_parse_builtin_cd_args(t_builtin_cd *parsed, t_opting *opting)
{
	char	**args;

	while (ms_getopt_parse(opting))
	{
		if (opting->optopt == 'L')
			parsed->symlink_follow = false;
		else if (opting->optopt == 'P')
			parsed->symlink_follow = true;
		else if (opting->optopt == 'e')
			parsed->is_set_cwd_error = true;
		else
			return (ms_perror_invalid_option("cd", opting->optopt),
				ms_print_usage_cd(), 2);
	}
	args = opting->argv + opting->optind;
	if (args[0] != NULL && args[1] != NULL)
		return (ms_perror_cmd("cd", "too many arguments"), 1);
	if (args[0] != NULL && ft_strcmp(args[0], "-") == 0)
		parsed->is_to_oldpwd = true;
	parsed->chdir_pathname = ms_get_cd_path(args[0]);
	if (parsed->chdir_pathname == NULL)
		return (ms_perror_cmd("cd", strerror(errno)), 1);
	return (0);
}
