/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_expansion_wildcard.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:31:02 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 18:26:46 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHNAME_EXPANSION_WILDCARD_H
# define PATHNAME_EXPANSION_WILDCARD_H

# include "pathname_expantion_internal_type.h"

char	**ms_get_file_list_from_dir(char *dir_name);
char	**ms_check_match_wildcard(char *token_string, int index,
			char *dir_name, char **file_list);
char	**ms_pathname_expansion_wildcard(char *dir_name, char *token);

#endif