/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper_type.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:44:16 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 20:49:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HELPER_TYPE_H
# define PARSE_HELPER_TYPE_H

# include "syntax_analyze_type.h"

typedef int	(*t_parse_helper_func)(
		t_token **tokens, int pos, t_list **syntax_lst, t_parse_func *parsers);

#endif
