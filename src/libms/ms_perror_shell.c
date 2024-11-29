/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:32:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 10:38:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ms_perror_shell(const char *msg)
{
	ft_dprintf(2, "minishell: %s\n", msg);
	return ;
}
