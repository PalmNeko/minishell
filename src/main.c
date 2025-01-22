/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:30:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 11:00:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "input.h"
#include <stdio.h>

int	main(void)
{
	t_minishell	*mnsh;

	mnsh = ms_setup();
	if (mnsh == NULL)
		return (1);
	ms_input(*mnsh);
	ms_cleanup_and_exit(0);
	return (0);
}
