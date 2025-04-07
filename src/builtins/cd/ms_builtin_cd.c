/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 06:29:14 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/07 11:38:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_internal.h"
#include "builtin_internal.h"
#include "libft.h"
#include "libms.h"
#include "ms_error.h"
#include "ft_printf.h"
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	ms_builtin_cd2(t_builtin_cd *parsed);
static int	ms_setnewpwd(t_builtin_cd *parsed, const char *chdir_pathname);
static char	*ms_create_newpwd(
				t_builtin_cd *parsed,
				const char *curdir,
				const char *chdir_pathname);

int	ms_builtin_cd(const char *path, char *const argv[], char *const envp[])
{
	t_builtin_cd	parsed;
	int				status;

	status = ms_parse_builtin_cd_args(&parsed, path, argv, envp);
	if (status != 0)
		return (status);
	status = ms_builtin_cd2(&parsed);
	free(parsed.chdir_pathname);
	return (status);
}

static int	ms_builtin_cd2(t_builtin_cd *parsed)
{
	char	*resolved_path;
	int		result;

	resolved_path = ms_resolve_with_cdpath(parsed->chdir_pathname);
	if (resolved_path == NULL)
		return (ms_perror_cmd("cd", strerror(errno)), 1);
	if (chdir(resolved_path) == -1)
		return (ms_perror_cd(resolved_path), free(resolved_path), 1);
	if (parsed->is_to_oldpwd)
		ft_printf("%s\n", resolved_path);
	result = ms_setnewpwd(parsed, resolved_path);
	free(resolved_path);
	return (result);
}

static int	ms_setnewpwd(t_builtin_cd *parsed, const char *chdir_pathname)
{
	char	*new_pwd;
	char	*curdir;
	int		result;
	bool	is_cwd_error;

	curdir = ms_get_current_dir_name();
	if (curdir == NULL)
		ms_perror_cwd("cd");
	new_pwd = ms_create_newpwd(parsed, curdir, chdir_pathname);
	if (new_pwd == NULL)
		return (free(curdir), ms_perror_cd(chdir_pathname), 1);
	is_cwd_error = curdir == NULL;
	free(curdir);
	result = ms_set_pwd_env(new_pwd);
	free(new_pwd);
	if (result != 0)
		return (ms_perror_cd(chdir_pathname), result);
	if (is_cwd_error && parsed->is_set_cwd_error && parsed->symlink_follow)
		return (1);
	return (0);
}

static char	*ms_create_newpwd(
				t_builtin_cd *parsed,
				const char *curdir,
				const char *chdir_pathname)
{
	char	*old_cdwd;
	char	*abs_path;
	char	*new_pwd;

	old_cdwd = ms_get_cdwd();
	if (old_cdwd == NULL)
		return (NULL);
	abs_path = ms_get_full_path(old_cdwd, chdir_pathname);
	if (abs_path == NULL)
		return (NULL);
	if (curdir == NULL)
		new_pwd = ft_strdup(abs_path);
	else if (parsed->symlink_follow == false)
		new_pwd = ms_normalize_path(abs_path);
	else if (parsed->symlink_follow == true)
		new_pwd = ft_strdup(curdir);
	else
		new_pwd = NULL;
	free(abs_path);
	return (new_pwd);
}
