/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:58:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/05 13:50:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_GETOPT_H
# define MS_GETOPT_H

# include "ms_getopt_type.h"

int		ms_getopt_init(
			t_opting *opting, int argc, char *argv[], const char *optstring);
bool	ms_getopt_parse(t_opting *opting);

#endif
