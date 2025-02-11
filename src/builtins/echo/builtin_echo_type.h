/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_type.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:31:16 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 16:43:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ECHO_TYPE_H
# define BUILTIN_ECHO_TYPE_H

# include <stdbool.h>

typedef struct s_builtin_echo
{
	bool	is_n;
	int		arg_index;
}	t_builtin_echo;

#endif
