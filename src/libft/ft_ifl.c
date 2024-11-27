/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:18:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/06 15:22:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * @brief like ternary operator for long.
 *
*/
long	ft_ifl(bool condition, long iftrue, long iffalse)
{
	if (condition)
		return (iftrue);
	else
		return (iffalse);
}
