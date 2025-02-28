/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal_type.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:10:57 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/02 10:52:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_INTERNAL_TYPE_H
# define EXPORT_INTERNAL_TYPE_H

# include <stdbool.h>

typedef struct s_builtin_export
{
	bool	is_print;
	char	**names;
}	t_builtin_export;

#endif
