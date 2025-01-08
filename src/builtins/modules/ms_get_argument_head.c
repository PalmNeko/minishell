/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/libft/ft_lstiter_bonus.c
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:43:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/16 15:31:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	if (lst == NULL)
		return ;
	if (lst->prev != NULL)
		lst->prev->next = NULL;
	iter = lst;
	while (iter != NULL)
	{
		f(iter->content);
		iter = iter->next;
	}
	if (lst->prev != NULL)
		lst->prev->next = lst;
	return ;
========
/*   ms_get_argument_head.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:13:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/28 19:00:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include <stddef.h>

char	**ms_get_argument_head(char *const argv[], const char *valid_opts)
{
	if (argv[0] == NULL)
		return (NULL);
	argv++;
	while (*argv != NULL)
	{
		if (ms_validate_opts(*argv, valid_opts) == false)
			return ((char **)argv);
		argv++;
	}
	return ((char **)argv);
>>>>>>>> origin/main:src/builtins/modules/ms_get_argument_head.c
}
