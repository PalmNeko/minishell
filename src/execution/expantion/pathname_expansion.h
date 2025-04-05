/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_expansion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:35:42 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/31 14:58:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHNAME_EXPANSION_H
# define PATHNAME_EXPANSION_H

char			**ms_pathname_expansion_wildcard(char *token, char *dir_name);
char			*ms_expand_path2(char *token);
t_syntax_node	*ms_remove_null_children(t_syntax_node *node);

#endif
