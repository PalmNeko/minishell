/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 19:47:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

# include <stdbool.h>

bool	ms_has_opt(char *const argv[], char opt, const char *valid_opts);
bool	ms_is_option(const char *arg);
bool	ms_validate_opts(const char *opts, const char *valid_opts);
void	ms_set_character_map(const char *str, bool map[256]);
char	*ms_get_first_invalid_opt(char *const argv[], const char *valid_opts);
char	**ms_get_argument_head(char *const argv[], const char *valid_opts);

#endif
