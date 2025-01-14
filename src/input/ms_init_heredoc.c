/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:47:42 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/11 12:47:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <stdlib.h>

void	ms_init_heredoc(t_heredoc *heredoc)
{
	heredoc->delimita_count = 0;
	heredoc->delimita_list = NULL;
}
