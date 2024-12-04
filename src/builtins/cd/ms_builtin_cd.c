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
#include "libms.h"
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

static int	ms_error_handling_cd(
				const char *path, char *const argv[], char *const envp[]);
static void	ms_print_usage_env(void);

int	ms_builtin_cd(
		const char *path, char *const argv[], char *const envp[])
{
	int result;
	char *arg;
	char *path;
	char **arg_head;
	char *opt;

	result = ms_error_handling_cd(path, argv, envp);
	if (result != 0)
		return (result);
	path = ms_get_cd_path(argv);
	if (path == NULL)
		return (1);
	result = ms_set_pwd_env(path) != 0 || chdir(path) != 0;
	free(path);
	if (result != 0)
		return (ms_perror_cmd2("cd", arg, strerror(errno)), 1);
	return (0);
}

int ms_set_pwd_env(const char *new_path)
{
	char	**pwd_value;
	char	*new_pwd;

	*pwd_value = ms_get_pwd();
	if (*pwd_value == NULL)
		return (1);
	if (ms_setenv("OLDPWD", *pwd_value, 1) != 0)
		return (1);
	new_pwd = ft_strdup(new_path);
	if (new_pwd == NULL)
		return (1);
	free(*pwd_value);
	*pwd_value = new_pwd;
	if (ms_setenv("PWD", new_path, 1) != 0)
		return (1);
	return (0);
}

// return the last valid option
char	*ms_get_opt_lp(char *const argv[])
{
	char	*opt;
	size_t	index;
	size_t	inner;

	index = 0;
	if (argv[0] == NULL)
		return (NULL);
	argv++;
	while (ms_validate_opts(argv[index], "LPe"))
	{
		inner = 1;
		while (argv[index][inner] != '\0')
		{
			if (argv[index][inner] == 'L' || argv[index][inner] == 'P')
				opt = argv[index] + inner;
			inner++;
		}
		index++;
	}
	return (opt);
}

int ms_error_handling_cd(
		const char *path, char *const argv[], char *const envp[])
{
}

char	*ms_get_cd_path(char *const argv[])
{
	char	**arg_head;
	char	*arg;
	char	*opt;
	char	*path;

	arg_head = ms_get_argument_head(argv, "LPe");
	if (arg_head == NULL)
		return (NULL);
	if (arg_head[0] != NULL && ft_strcmp(arg_head[0], "--") == 0)
		arg_head++;
	arg = arg_head[0];
	env = NULL;

	path =
	return (path);
}

char	*ms_interpret_path(const char *path)
{
	if (path == NULL)
	{
		path = ms_getenv("HOME");
		if (path == NULL)
			return (ms_perror_cmd("cd", "HOME not set"), NULL);
		path = ft_strdup(path);
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		path = ms_getenv("OLDPWD");
		if (path == NULL)
			return (ms_perror_cmd("cd", "OLDPWD not set"), NULL);
		path = ft_strdup(path);
	}
	else if (ft_strchr(path, '/') != NULL)
		path = ft_strdup(path);
	else
		path = ms_resolve_path(path, ms_getenv("CDPATH"));
}

char	*ms_resolve_path(const char *path, const char *pathdirs)
{

}

char	*ms_get_ppath(const char *pathname)
{

}

char	*ms_get_lpath(const char *pathname)
{

}
