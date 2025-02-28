/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:09:32 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/30 19:29:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "readline_var.h"

char	*ms_readline(const char *prompt);
int		ms_setup_readline_handler(void);
int		ms_setup_readline_behavior(void);

#endif
