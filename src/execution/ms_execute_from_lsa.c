/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_from_lsa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:26:10 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/26 21:31:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ms_execute_from_lsa(t_lsa *lsa)
{
	int	ret;

	ret = ms_execute_lists(lsa->lists);
	return (ret);
}
