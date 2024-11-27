/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_rewrite_special_behavior.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:24:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 17:04:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include "libft.h"
#include <stdio.h>

void	fp_rewrite_special_behavior(t_cs *cs)
{
	if (cs->flag_minus == true)
		cs->flag_zero = false;
	if (cs->flag_plus == true)
		cs->flag_space = false;
	if (cs->is_set_precision == true && (ft_includes(cs->type, "diuxXp")))
		cs->flag_zero = false;
	if (cs->is_set_precision == false && (ft_includes(cs->type, "diuxXp")))
		cs->precision = 1;
	if (! ft_includes(cs->type, "xXp"))
		cs->flag_sharp = false;
	if (cs->type == 'p')
		cs->flag_sharp = true;
	return ;
}
