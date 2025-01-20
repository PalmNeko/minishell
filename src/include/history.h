/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:13:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:20:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

/**
 * functions
 */
int		ms_read_history(const char *filename);
int		ms_write_history(const char *filename);
void	ms_add_history(const char *string);
void	ms_stifle_history(int max);
int		ms_unstifle_history(void);
int		ms_history_truncate_file(const char *filename, int nlines);
void	ms_clear_history(void);
void	ms_update_history_variable(void);
void	ms_add_mnsh_history(const char *string);
int		ms_append_history(int nelements, const char *filename);
void	ms_reset_histcmd(void);
int		ms_get_histcmd(void);

/**
 * variables
 */
int		ms_history_length(void);
int		ms_history_max_entries(void);
void	ms_set_history_length(int length);
void	ms_set_history_max_entries(int max_entries);

#endif
