/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memento.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:15:48 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 12:12:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMENTO_H
# define MEMENTO_H

# include "memento_type.h"

t_environ_memento	*ms_save_environ_memento(void);
int					ms_restore_environ_memento(t_environ_memento *memento);
void				ms_memento_destroy(t_environ_memento *memento);

#endif
