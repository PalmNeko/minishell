/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:27:56 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 21:01:50 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "execution.h"
#include "libms.h"
#include "setup.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char	*ms_execute_command_get_path(char *command, char *envpath);

int	ms_execute_command(char **args)
{
	int		ret;
	char	**envp;
	char	*envpath;
	char	*temp;

	envp = ms_export_env();
	if (ms_isbuiltin(args[0]))
	{
		ret = ms_builtin(args[0], args, envp);
		ms_destroy_ntp2((void **)envp, free);
		return (ret);
	}
	temp = args[0];
	envpath = ms_getenv("PATH");
	if (ft_strchr(args[0], '/') == NULL && envpath != NULL)
	{
		temp = ms_execute_command_get_path(args[0], envpath);
		if (temp == args[0])
		{
			ms_perror_cmd(args[0], "command not found");
			return (127);
		}
	}
	if (ms_is_dir(args[0]) == 1)
	{
		ms_perror_cmd(args[0], "is a directory");
		return (126);
	}
	ret = execve(temp, args, envp);
	if (ret == -1)
		ms_perror_cmd(args[0], strerror(errno));
	ms_destroy_ntp2((void **)envp, free);
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
