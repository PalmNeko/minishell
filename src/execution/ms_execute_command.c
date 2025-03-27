/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:27:56 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/25 09:36:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "execution.h"
#include "libms.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char	*ms_execute_command_get_path(char *command, char *envpath);
static int	ms_execute_command_builtin(char **args);
static int	ms_execute_command_external(char **args);

/*Note
	Need to check the envp attribute(Is set attribute?)
*/

int	ms_execute_command(char **args)
{
	int	ret;

	if (ms_isbuiltin(args[0]))
		return (ms_execute_command_builtin(args));
	ret = ms_execute_command_external(args);
	if (ret == -1)
	{
		if (errno == ENOENT || errno == EACCES)
			ret = 127;
		else
			ret = 126;
		ms_perror_cmd(args[0], strerror(errno));
	}
	else if (ret == 127)
		ms_perror_cmd(args[0], "command not found");
	return (ret);
}

static char	*ms_execute_command_get_path(char *command, char *envpath)
{
	char	*tmp;
	char	**path_list;
	int		i;

	path_list = ft_split(envpath, ':');
	if (path_list == NULL)
		return (NULL);
	i = 0;
	while (path_list[i])
	{
		tmp = ms_get_full_path(path_list[i], command);
		if (access(tmp, F_OK) == 0)
		{
			ms_destroy_ntp2((void **)path_list, free);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	ms_destroy_ntp2((void **)path_list, free);
	return (command);
}

static int	ms_execute_command_builtin(char **args)
{
	int		ret;
	char	**envp;

	envp = ms_export_env();
	ret = ms_builtin(args[0], args, envp);
	ms_destroy_ntp2((void **)envp, free);
	return (ret);
}

static int	ms_execute_command_external(char **args)
{
	char	**envp;
	char	*path;
	char	*envpath;
	int		ret;
	int		enobuf;

	envp = ms_export_env();
	path = args[0];
	envpath = ms_getenv("PATH");
	if (ft_strchr(args[0], '/') == NULL && envpath != NULL)
	{
		path = ms_execute_command_get_path(args[0], envpath);
		if (path == args[0])
		{
			ms_destroy_ntp2((void **)envp, free);
			return (127);
		}
	}
	ret = execve(path, args, envp);
	enobuf = errno;
	if (errno == EACCES && ms_isadir(path))
		enobuf = EISDIR;
	errno = enobuf;
	ms_destroy_ntp2((void **)envp, free);
	return (ret);
}
