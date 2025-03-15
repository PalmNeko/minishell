/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:14:42 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 19:14:43 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_TYPE_H

# define EXECUTION_TYPE_H

typedef enum e_state_in_command
{
	MIDDLE_COMMAND,
	FIRST_COMMAND,
	LAST_COMMAND,
	SINGLE_COMMAND,
}	t_state_in_pipeline;
#endif