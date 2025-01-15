/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:44:53 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/15 13:45:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_TYPE_H
# define SETUP_TYPE_H

# include "libft.h"

typedef t_list	t_ms_var_list;
typedef t_list	t_ms_malloc_list;

typedef struct minishell {
	t_ms_var_list		*ms_shell_var;
	t_ms_malloc_list	*ms_malloc_list;
}	t_minishell;

typedef struct s_ms_var {
	char	*name;
	char	*value;
	int		attr;
}	t_var;

typedef struct s_ms_malloc {
	void	*ptr;
}	t_ms_malloc;

#endif
