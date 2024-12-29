/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_delete_special_directory.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:48:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 18:48:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include <stdlib.h>

int		ms_normalize_path_join(t_list **lst, char *path);
char	*ms_normalize_pathlst_join(t_list *lst);

/**
 * delete . and ..
 */
char	*ms_normalize_path(const char *path)
{
	char	**paths;
	char	**root;
	t_list	*lst;

	paths = ft_split(path, '/');
	if (paths == NULL)
		return (NULL);
	root = paths;
	lst = NULL;
	while (*paths != NULL)
	{
		if (ms_normalize_path_join(&lst, *(paths++)) != 0)
		{
			ms_destroy_ntp(root);
			ft_lstclear(&lst, (void (*)(void *))ft_voidnop);
			return (NULL);
		}
	}
	return (ms_normalize_pathlst_join(lst));
}

int	ms_normalize_path_join(t_list **lst, char *path)
{
	t_list	*tmp;

	tmp = ft_lstnew(path);
	if (tmp == NULL)
		return (1);
	if (ft_strcmp(path, ".") == 0)
		return (free(tmp), 0);
	else if (ft_strcmp(path, "..") == 0)
		ft_lstpop(lst);
	else
		ft_lstpush(lst, tmp);
	return (0);
}

char	*ms_normalize_pathlst_join(t_list *lst)
{
	t_list	*end;
	char	*path;
	char	*tmp;

	if (lst == NULL)
		return (ft_strdup("/"));
	path = ft_strdup("");
	if (path == NULL)
		return (NULL);
	end = ft_lstlast(lst);
	while (end != NULL)
	{
		tmp = ft_strjoin(path, "/");
		free(path);
		path = tmp;
		if (tmp == NULL)
			return (NULL);
		tmp = ft_strjoin(path, end->content);
		free(path);
		if (tmp == NULL)
			return (NULL);
		path = tmp;
		end = end->prev;
	}
	return (path);
}
