/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_memento_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:12:52 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 12:13:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memento_type.h"
#include <stdlib.h>

void	ms_memento_destroy(t_environ_memento *memento)
{
	free(memento);
}
