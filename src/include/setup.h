/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/18 17:43:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "libft.h"
# include "setup_type.h"

t_minishell	*ms_setup(void);
void		ms_cleanup_and_exit(int status);

// internal 行き
int			ms_setup_history(void);
bool		ms_is_interactive(void);

#endif
