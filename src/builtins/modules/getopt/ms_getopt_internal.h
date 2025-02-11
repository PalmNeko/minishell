/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getopt_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:14:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 15:53:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_GETOPT_INTERNAL_H
# define MS_GETOPT_INTERNAL_H

# include "ms_getopt_type.h"

void	ms_skip_double_hyphen_if_needed(t_opting *opting);
bool	ms_is_parsed(t_opting *opting);
bool	ms_is_valid_statement(const char *arg, const char *optstring);
bool	ms_opt_is_valid(int opt, const char *optstring);
bool	ms_go_is_option(const char *arg);

#endif
