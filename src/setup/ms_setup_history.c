/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:14:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 14:16:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "history.h"
#include "setup.h"
#include <stdio.h>

int	ms_setup_history(void)
{
	char	*filename;

	if (ms_is_interactive() == false)
		return (0);
	filename = ms_getenv("HISTFILE");
	if (filename == NULL)
		filename = "~/.mnsh_history";
	ms_read_history(filename);
	return (0);
}
