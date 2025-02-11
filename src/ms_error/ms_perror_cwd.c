/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:13:51 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 07:31:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"

void	ms_perror_cwd(const char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": error retrieving current directory: "
		"getcwd: cannot access parent directories: "
		"No such file or directory\n", 2);
}
