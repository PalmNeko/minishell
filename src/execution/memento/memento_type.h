/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memento_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:16:04 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 20:16:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMENTO_TYPE_H
# define MEMENTO_TYPE_H

typedef struct s_environ_memento {
	int	stdin_fd;
	int	stdout_fd;
	int	stderr_fd;
}	t_environ_memento;

#endif
