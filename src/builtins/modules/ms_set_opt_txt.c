/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_opt_txt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:25:01 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/30 17:20:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

char	*ms_set_opt_txt(char buf[3], char invalid_opt)
{
	buf[0] = '-';
	buf[1] = invalid_opt;
	buf[2] = '\0';
	return (buf);
}
