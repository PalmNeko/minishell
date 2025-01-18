/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:14:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/18 18:04:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "history.h"
#include <stdio.h>

int	ms_setup_history(void)
{
	char	*filename;

	filename = ms_getenv("HISTFILE");
	if (filename == NULL)
		filename = "~/.mnsh_history";
	ms_read_history(filename);
	return (0);
}
