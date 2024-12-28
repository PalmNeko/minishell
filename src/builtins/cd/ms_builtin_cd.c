/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:25:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/04 14:25:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin_internal.h"
#include "cd_internal.h"
#include "libms.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>

static char	*ms_create_newpwd(
				char *const argv[],
				const char *curdir,
				const char *chdir_pathname);
static char	*ms_get_chdir_path(char *const argv[]);
static int	ms_setnewpwd(char *const argv[], const char *chdir_pathname);

int	ms_builtin_cd(
		const char *path, char *const argv[], char *const envp[])
{
	int		status;
	char	*chdir_pathname;

	status = ms_error_handling_cd(path, argv, envp);
	if (status != 0)
		return (status);
	if (*(ms_get_raw_cdwd()) == NULL)
		free(ms_get_cdwd());
	chdir_pathname = ms_get_chdir_path(argv);
	if (chdir_pathname == NULL)
		return (1);
	printf("chdir_pathname: %s\n", chdir_pathname);
	if (chdir(chdir_pathname) == -1)
		return (ms_perror_cd(chdir_pathname), 1);
	status = ms_setnewpwd(argv, chdir_pathname);
	free(chdir_pathname);
	return (status);
}

static char	*ms_get_chdir_path(char *const argv[])
{
	char	*chdir_pathname;
	char	*target_pathname;
	char	**arg_head;

	arg_head = ms_get_first_arg_ptr(argv, "LPe");
	target_pathname = ms_get_cd_path(arg_head[0]);
	if (target_pathname == NULL)
		return (NULL);
	chdir_pathname = ms_resolve_with_cdpath(target_pathname);
	if (chdir_pathname == NULL)
		return (ms_perror_cd(target_pathname), free(target_pathname), NULL);
	free(target_pathname);
	return (chdir_pathname);
}

static int	ms_setnewpwd(char *const argv[], const char *chdir_pathname)
{
	char	*new_pwd;
	char	*curdir;
	int		result;
	bool	is_cwd_error;

	curdir = ms_get_current_dir_name();
	if (curdir == NULL)
		ms_perror_cd_cwd();
	new_pwd = ms_create_newpwd(argv, curdir, chdir_pathname);
	if (new_pwd == NULL)
		return (free(curdir), ms_perror_cd(chdir_pathname), 1);
	is_cwd_error = curdir == NULL;
	free(curdir);
	printf("new_pwd: %s\n", new_pwd);
	result = ms_set_pwd_env(new_pwd);
	free(new_pwd);
	if (result != 0)
		return (ms_perror_cd(chdir_pathname), result);
	if (is_cwd_error && ms_is_cwd_check(argv))
		return (1);
	return (0);
}

static char	*ms_create_newpwd(
				char *const argv[],
				const char *curdir,
				const char *chdir_pathname)
{
	char	*old_cdwd;
	char	*abs_path;
	char	*new_pwd;

	old_cdwd = ms_get_cdwd();
	if (old_cdwd == NULL)
		return (NULL);
	printf("old_cdwd: %s\n", old_cdwd);
	abs_path = ms_get_full_path(old_cdwd, chdir_pathname);
	printf("abs_path: %s\n", abs_path);
	free(old_cdwd);
	if (curdir == NULL)
		new_pwd = ft_strdup(abs_path);
	else if (ms_is_unresolve_symlink(argv))
		new_pwd = ms_normalize_path(abs_path);
	else if (ms_is_resolve_symlink(argv))
		new_pwd = ft_strdup(curdir);
	else
		new_pwd = NULL;
	free(abs_path);
	return (new_pwd);
}
