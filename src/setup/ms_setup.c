/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:29:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/18 11:25:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "setup_internal.h"

t_minishell	*ms_setup(void)
{
	ms_setup_variable();
	ms_setup_history();
	ms_set_handle();
	return (NULL);
}
