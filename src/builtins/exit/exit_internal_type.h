/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_internal_type.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:36:37 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/06 12:29:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_INTERNAL_TYPE_H
# define EXIT_INTERNAL_TYPE_H

# include <stdbool.h>

typedef struct s_builtin_exit
{
	int		exit_status;
	bool	is_exit;
}	t_builtin_exit;

#endif
