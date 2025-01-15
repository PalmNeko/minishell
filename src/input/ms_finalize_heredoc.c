/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clean_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:47:32 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/11 12:47:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input.h"
#include <stdlib.h>

void	ms_finalize_heredoc(t_heredoc *heredoc)
{
	heredoc->delimita_count = 0;
	ft_lstclear(&heredoc->delimita_list, free);
	heredoc->delimita_list = NULL;
}
