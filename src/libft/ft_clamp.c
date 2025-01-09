/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:34:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/07 10:34:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * I refer this page: https://developer.mozilla.org/ja/docs/Web/CSS/clamp
 */
int	ft_clamp(int min, int val, int max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	else
		return (val);
}
