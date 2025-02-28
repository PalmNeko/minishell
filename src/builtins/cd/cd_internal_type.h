/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_internal_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 05:44:12 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/01 07:48:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_INTERNAL_TYPE_H
# define CD_INTERNAL_TYPE_H

# include <stdbool.h>

typedef struct s_builtin_cd
{
	bool	symlink_follow;
	bool	is_set_cwd_error;
	char	*chdir_pathname;
}	t_builtin_cd;

#endif
