/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_compound_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:22 by nyts              #+#    #+#             */
/*   Updated: 2025/04/06 10:16:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	ms_increase_mnsh_subshell(void);

int	ms_execute_compound_lists(t_lsa_list **lists)
{
	int		ret;
	pid_t	pid;

	ret = 0;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		ms_set_default_signal();;
		if (ms_is_mnsh_subshell_var_enabled())
			ms_increase_mnsh_subshell();
		ret = ms_execute_lists(lists);
		ret = ms_add_meta(ret, IS_CHILD);
	}
	else
		waitpid(pid, &ret, 0);
	return (ret);
}

static void	ms_increase_mnsh_subshell(void)
{
	int		subshell;
	char	*subshell_str;

	subshell_str = ms_getenv("MNSH_SUBSHELL");
	if (subshell_str == NULL)
		return ;
	subshell = ms_shell_atoi(subshell_str);
	subshell++;
	subshell_str = ft_itoa(subshell);
	ms_setenv("MNSH_SUBSHELL", subshell_str, 1);
	free(subshell_str);
}
