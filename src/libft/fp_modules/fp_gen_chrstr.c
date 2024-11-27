/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_chrstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:10:07 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 13:36:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"

char	*fp_gen_chrstr(t_cs *cs, int *len, unsigned char uchr)
{
	char	*str;

	(void)cs;
	str = fp_convert_uchr2str(len, uchr);
	return (str);
}
