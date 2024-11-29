/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:36:26 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 10:37:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ms_perror_cmd(const char *name, const char *msg)
{
	ft_dprintf(2, "minishell: %s: %s\n", name, msg);
	return ;
}
