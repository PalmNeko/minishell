/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 16:17:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

char	*ms_extract_builtin_options(char *const argv[]);
char	*ms_get_invalid_options(const char *opts, const char *valid_opts);
char	*ms_has_options(const char *opts, const char *check_opts);
char	**ms_extract_builtin_arguments(char *const argv[]);

#endif
