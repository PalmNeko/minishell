/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 14:05:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

# include <stdbool.h>

char	*ms_extract_opts(char *const argv[]);
char	*ms_get_invalid_opts(const char *opts, const char *valid_opts);
char	**ms_extract_args(char *const argv[]);
char	**ms_exclude_valid_opts(char *const argv[], const char *valid_opts);
bool	ms_has_opts(const char *opts, const char *check_opts);
bool	ms_is_option(const char *arg);
bool	ms_validate_opts(const char *opts, const char *valid_opts);
void	ms_set_character_map(const char *str, bool map[256]);
char	*ms_create_string_from_map(const bool map[256]);

#endif
