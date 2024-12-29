/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_first_arg_ptr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:07 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 14:47:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin_internal.h"
#include <stddef.h>

char	**ms_get_first_arg_ptr(char *const argv[], const char *valid_opt)
{
	char	**arg_head;

	arg_head = ms_get_argument_head(argv, valid_opt);
	if (arg_head[0] != NULL && ft_strcmp(arg_head[0], "--") == 0)
		arg_head++;
	return (arg_head);
}
