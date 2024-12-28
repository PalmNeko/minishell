/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:51:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/27 18:51:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"

t_builtin_func	ms_return_builtin_func(const char *command_name);

int	ms_builtin(const char *path, char *const argv[], char *const envp[])
{
	t_builtin_func	func;

	func = ms_return_builtin_func(argv[0]);
	if (func == NULL)
		return (1);
	return (func(path, argv, envp));
}

t_builtin_func	ms_return_builtin_func(const char *command_name)
{
	t_cmd_list	*cmd_list;

	cmd_list = (t_cmd_list[]){
	{.cmd = "echo", .func = ms_builtin_echo},
	{.cmd = "pwd", .func = ms_builtin_pwd},
	{.cmd = "unset", .func = ms_builtin_unset},
	{.cmd = "env", .func = ms_builtin_env},
	{.cmd = "exit", .func = ms_builtin_exit},
	{.cmd = "cd", .func = ms_builtin_cd},
	{.cmd = "export", .func = ms_builtin_export},
	{.cmd = NULL, .func = NULL}};
	while (cmd_list->cmd != NULL)
	{
		if (ft_strcmp(command_name, cmd_list->cmd) == 0)
			return (cmd_list->func);
		cmd_list++;
	}
	return (NULL);
}
