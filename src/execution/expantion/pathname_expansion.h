/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_expansion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:35:42 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 17:52:45 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHNAME_EXPANSION_H
# define PATHNAME_EXPANSION_H

char	**ms_pathname_expansion_wildcard(char *token, char *dir_name);
char	*ms_expand_path2(char *token);

#endif