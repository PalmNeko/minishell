/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_string_to_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:48:39 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/14 05:51:35 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include <stdlib.h>

int	ms_add_string_to_lst(t_list **file_list_lst, char *filename)
{
	char	*file;

	file = ft_strdup(filename);
	if (file == NULL)
		return (-1);
	if (ms_lst_append_tail(file_list_lst, file) == -1)
	{
		free(file);
		return (-1);
	}
	return (0);
}
