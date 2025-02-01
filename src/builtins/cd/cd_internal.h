/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:58:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 16:58:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_INTERNAL_H
# define CD_INTERNAL_H

# include "cd_internal_type.h"
# include <stdbool.h>

int		ms_error_handling_cd(
			const char *path, char *const argv[], char *const envp[]);
char	*ms_get_cd_path(const char *arg_path);
char	*ms_get_opt_lp(char *const argv[]);
bool	ms_is_cwd_check(char *const argv[]);
bool	ms_is_resolve_symlink(char *const argv[]);
bool	ms_is_unresolve_symlink(char *const argv[]);
bool	ms_is_use_cdpath(const char *path);
void	ms_perror_cd_cwd(void);
void	ms_print_usage_cd(void);
char	*ms_resolve_with_cdpath(const char *path);
char	*ms_search_with_cdpath(const char *path);
int		ms_set_pwd_env(const char *new_path);
int		ms_parse_builtin_cd_args(
			t_builtin_cd *parsed,
			const char *path,
			char *const argv[],
			char *const envp[]);

#endif
