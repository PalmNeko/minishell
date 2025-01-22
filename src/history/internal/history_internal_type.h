/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_internal_type.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:25:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:25:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_INTERNAL_TYPE_H
# define HISTORY_INTERNAL_TYPE_H

# include "libft.h"

typedef struct s_history
{
	t_list	*history;
	int		history_length;
	int		history_max_entries;
	int		history_cmd;
	bool	enable_history_cmd;
}	t_history;

#endif
