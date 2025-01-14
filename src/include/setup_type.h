/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:49:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/09 17:49:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_TYPE_H
# define SETUP_TYPE_H

# include "libft.h"

typedef t_list	t_ms_var_list;
typedef t_list	t_ms_malloc_list;

typedef struct minishell
{
	t_ms_var_list		*ms_shell_var;
	t_ms_malloc_list	*ms_malloc_list;
}	t_minishell;

#endif
