/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 05:21:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "libft.h"
# include "setup_type.h"

t_minishell	*ms_setup(void);
void		ms_cleanup_and_exit(int status);
t_minishell	*ms_get_minishell(void);
void		ms_set_minishell(t_minishell *ms);

// to internal
void		ms_setup_variable(void);
int			ms_setup_history(void);
bool		ms_is_interactive(void);
int			ms_setup_global_variables(void);
void		ms_setup_export_environ(void);

#endif
