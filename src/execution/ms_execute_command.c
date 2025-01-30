/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:27:56 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/26 21:31:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "execution.h"
#include "setup.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ms_execute_command(char **args)
{
	int	ret;

	if (ms_isbuiltin(args[0]))
	{
		return (ms_builtin(args[0], args, NULL));
	}
	ret = execve(args[0], args, NULL);
	exit(ret);
}
