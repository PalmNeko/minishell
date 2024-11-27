/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_destroy_t_cs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:44:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 16:44:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fp_module.h"

void	fp_destroy_t_cs(t_cs *ptr)
{
	free(ptr);
	return ;
}
