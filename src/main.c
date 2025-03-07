/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:30:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 17:40:09 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "input.h"
#include <stdio.h>

int	main(void)
{
	t_minishell	*mnsh;
	int			status;

	mnsh = ms_setup();
	if (mnsh == NULL)
		return (1);
	status = ms_input(*mnsh);
	ms_cleanup_and_exit(status);
	return (0);
}
