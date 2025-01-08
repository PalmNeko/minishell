/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:37:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/02 16:46:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ms_perror_cmd2(const char *name, const char *type, const char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd((char *)name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd((char *)type, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd((char *)msg, 2);
	return ;
}
