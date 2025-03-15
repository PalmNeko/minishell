/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_file_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:15:16 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 08:00:52 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

static bool	is_current_or_parent_dir(char *filename);

char	**ms_get_file_list_from_dir(char *dir_name)
{
	DIR				*dir;
	struct dirent	*dp;
	t_list			*file_list_lst;
	char			**file_list;

	dir = opendir(dir_name);
	if (dir == NULL)
		return (NULL);
	dp = readdir(dir);
	file_list_lst = NULL;
	while (dp != NULL)
	{
		if (!is_current_or_parent_dir(dp->d_name)
			&& ms_add_string_to_lst(&file_list_lst, dp->d_name) == -1)
			return (ft_lstclear(&file_list_lst, free), NULL);
		dp = readdir(dir);
	}
	closedir(dir);
	file_list = ms_lst_to_ntp(&file_list_lst, ms_identify, ms_noop_del);
	return (file_list);
}

static bool	is_current_or_parent_dir(char *filename)
{
	return (ft_strcmp(filename, ".") == 0 || ft_strcmp(filename, "..") == 0);
}
