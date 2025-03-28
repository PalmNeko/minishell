/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_compound_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:22 by nyts              #+#    #+#             */
/*   Updated: 2025/03/28 05:44:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
		ret = ms_execute_lists(lists);
		ret = ms_add_meta(ret, IS_CHILD);
	}
	else
		waitpid(pid, &ret, 0);
	return (ret);
}
