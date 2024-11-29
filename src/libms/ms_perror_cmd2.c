/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:37:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 10:38:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ms_perror_cmd2(const char *name, const char *type, const char *msg)
{
	ft_dprintf(2, "minishell: %s: %s: %s\n", name, type, msg);
	return ;
}
