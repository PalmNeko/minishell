/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_compound_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:22 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 19:22:23 by nyts             ###   ########.fr       */
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
		exit(ret);
	}
	waitpid(pid, &ret, 0);
	return (ret);
}
