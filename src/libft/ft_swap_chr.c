/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:54:20 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 16:54:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_chr(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}