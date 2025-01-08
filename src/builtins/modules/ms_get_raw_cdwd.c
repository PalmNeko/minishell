/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/libft/ft_max.c
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:12:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:12:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
========
/*   ms_get_raw_cdwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:11:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 15:11:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*g_cdwd;

char	**ms_get_raw_cdwd(void)
{
	return (&g_cdwd);
>>>>>>>> origin/main:src/builtins/modules/ms_get_raw_cdwd.c
}
