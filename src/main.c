/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:30:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/18 17:48:13 by tookuyam         ###   ########.fr       */
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
	ms_setup();
	ms_input(mnsh);
	ms_cleanup_and_exit(0);
	return (0);
}
