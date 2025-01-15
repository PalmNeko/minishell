/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:30:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/15 17:42:52 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "setup.h"
#include "input.h"

int	main(void)
{
	t_minishell	mnsh = {};
	// 処理
	// mnsh = ms_setup();
	// if (mnsh == NULL)
	// 	return(1);
	
	ms_input(mnsh);
	ms_cleanup_and_exit(0);
	return (0);
}
