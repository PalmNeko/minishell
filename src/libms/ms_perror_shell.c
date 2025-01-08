/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:32:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/02 16:47:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ms_perror_shell(const char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd((char *)msg, 2);
	return ;
}
