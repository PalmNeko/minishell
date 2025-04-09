/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:43:17 by nyts              #+#    #+#             */
/*   Updated: 2025/04/09 19:43:49 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_REMOVAL_H
# define QUOTE_REMOVAL_H
# include "syntax_analyze_type.h"

t_syntax_node	*ms_remove_null_children(t_syntax_node *node);

#endif
