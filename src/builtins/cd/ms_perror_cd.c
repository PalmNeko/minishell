/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:19:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 14:19:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include <errno.h>
#include <string.h>

void	ms_perror_cd(const char *type)
{
	ms_perror_cmd2("cd", type, strerror(errno));
}
