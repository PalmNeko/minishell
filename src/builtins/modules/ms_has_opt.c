/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_has_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:51:43 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/16 01:51:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD:src/builtins/echo/ms_has_opt.c
#include "ms_int_echo.h"
#include "libft.h"
=======
#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
>>>>>>> origin/main:src/builtins/modules/ms_has_opt.c
#include <stdbool.h>
#include <stddef.h>

bool	ms_has_opt(char *const argv[], char opt, const char *valid_opts)
{
	if (argv[0] == NULL)
		return (false);
	argv++;
	while (*argv != NULL)
	{
		if (ms_validate_opts(*argv, valid_opts) == true)
		{
			if (ft_strchr(*argv + 1, opt) != NULL)
				return (true);
		}
		else
			return (false);
		argv++;
	}
	return (false);
}
