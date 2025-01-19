/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:22:08 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 12:10:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_INTERNAL_H
# define HISTORY_INTERNAL_H

# include "history_internal_type.h"

void		ms_add_history_history(t_history *history, const char *string);
void		ms_clear_history_history(t_history *history);
void		ms_stifle_history_history(t_history *history, int max);
void		ms_truncate_history_history(t_history *history, int nlines);
int			ms_unstifle_history_history(t_history *history);
int			ms_read_history_history(t_history *history, const char *filename);
int			ms_write_history_history(t_history *history, const char *filename);
void		ms_init_history(t_history *history);
int			ms_append_history_history(
				t_history *history, int nelements, const char *filename);
/**
 * variable
 */
t_history	ms_history(void);
void		ms_set_history(const t_history *history);

#endif
