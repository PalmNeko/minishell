/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:51:46 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/09 17:51:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TYPE_H
# define INPUT_TYPE_H

# include "libft.h"

typedef t_list	t_delimita_list;

typedef struct s_heredoc {
	size_t			delimita_count;
	t_delimita_list	*delimita_list;
}	t_heredoc;

#endif
