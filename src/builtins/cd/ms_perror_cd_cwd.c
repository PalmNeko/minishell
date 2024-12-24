/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cd_cwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:40:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 14:40:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"

void	ms_perror_cd_cwd()
{
	ms_perror_cd("error retrieving current directory: "
		"getcwd: cannot access parent directories");
}
