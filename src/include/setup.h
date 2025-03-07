/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 07:30:11 by tookuyam         ###   ########.fr       */
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

// internal 行き
void		ms_setup_variable(void);
int			ms_setup_history(void);
bool		ms_is_interactive(void);
int			ms_setup_global_variables(void);

#endif
